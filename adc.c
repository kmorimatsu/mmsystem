/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

#include <xc.h>

/*
 * AN0: RA0
 * AN1: RA1
 * AN2: RB0
 * AN3: RB1
 * AN4: RB2
 * AN5: RA2
 * AN6: RA3
 * AN7: RB12
 * AN8: RB13
 * AN9: RB14
 * AN10:RB15
 * AN11:RB3
 * Note: RB7-10 are not used. These are used for 7 seg LED.
 */

// Contain which ADC is/are used (AN0 - AN6, AN11)
static int g_used_adc;

void adc_init(int used_adc){
    int i,num;
    // Count # of ADC used
    num=0;
    // Store data in global area
    g_used_adc=used_adc & 0x087f;
    // Port input settings for ADC
    for(i=0;i<12;i++){
        if (used_adc&(1<<i)) {
            switch(i){
                case 0:  // RA0
                    ANSELASET=TRISASET=1<<0;
                    num++;
                    break;
                case 1:  // RA1
                    ANSELASET=TRISASET=1<<1;
                    num++;
                    break;
                case 2:  // RB0
                    ANSELBSET=TRISBSET=1<<0;
                    num++;
                    break;
                case 3:  // RB1
                    ANSELBSET=TRISBSET=1<<1;
                    num++;
                    break;
                case 4:  // RB2
                    ANSELBSET=TRISBSET=1<<2;
                    num++;
                    break;
                case 5:  // RA2
                    ANSELASET=TRISASET=1<<2;
                    num++;
                    break;
                case 6:  // RA3
                    ANSELASET=TRISASET=1<<3;
                    num++;
                    break;
                case 11: // RB3
                    ANSELBSET=TRISBSET=1<<3;
                    num++;
                    break;
                default:
                    break;
            }    
        }
    }
    
    if (!num) return;
    
    // Prepare ADC
    AD1CON1bits.ON=0;
    AD1CON1bits.SIDL=0;
    AD1CON1bits.FORM=0;
    AD1CON1bits.SSRC=6; // Use Timer1 for triggering sampling
    AD1CON1bits.MODE12=1;
    AD1CON1bits.ASAM=1;
    AD1CON1bits.SAMP=0;
    AD1CON1bits.DONE=0;
    AD1CON2bits.VCFG=0;
    AD1CON2bits.OFFCAL=0;
    AD1CON2bits.BUFREGEN=1; // Use corresponding buffer for each ADC module
    AD1CON2bits.CSCNA=1; // Scans inputs
    AD1CON2bits.BUFS=0;
    AD1CON2bits.SMPI=num-1;
    AD1CON2bits.BUFM=0;
    AD1CON3bits.ADRC=0;
    AD1CON3bits.EXTSAM=0;
    AD1CON3bits.SAMC=0x1f; //?
    AD1CON3bits.ADCS=23; // TAD >280 ns (357k Hz; 1/22.4 of 8M Hz)
    AD1CON5bits.ASEN=0;
    AD1CON5bits.LPEN=0;
    AD1CON5bits.BGREQ=0;
    AD1CON5bits.ASINT=0;
    AD1CON5bits.WM=0;
    AD1CON5bits.CM=0;
    AD1CSS=used_adc;

    AD1CON1bits.ON=1;
    AD1CON1bits.SAMP=1;
    
    // Wait until at least one data received for each AN.
    for(i=0;i<16;i++) asm("wait");
}

unsigned int adc_read(int adc_num){
    // Return 0 if invalid number is passed.
    if (!(g_used_adc & (1<<adc_num))) return 0;
    // Return result read from ADC1BUFx.
    switch(adc_num){
        case 0:  // RA0
            return ADC1BUF0;
        case 1:  // RA1
            return ADC1BUF1;
        case 2:  // RB0
            return ADC1BUF2;
        case 3:  // RB1
            return ADC1BUF3;
        case 4:  // RB2
            return ADC1BUF4;
        case 5:  // RA2
            return ADC1BUF5;
        case 6:  // RA3
            return ADC1BUF6;
        case 11: // RB3
            return ADC1BUF11;
        default:
            return 0;
            break;
    }    
}
