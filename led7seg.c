/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "led7seg.h"

// Timer 1 interruption frequency must be about 2000 Hz
// As a result, one round of 7 seg display occurs every 16m seconds.
// This frequency also works for anti-chattering of key inputs.
#define TIMER1COUNT (4096*MM_SYSTEM_CLOCK/8000000)

volatile unsigned char g_keydata[8];

volatile unsigned char g_leddata[4];

const unsigned char g_dec2led[16]=
    {0x3f,0x6,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71,};
//	{0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe4,0xfe,0xf6,0xee,0x3e,0x1a,0x7a,0x9e,0x8e,};

// Division macro for unsigned long
// Valid for 31 bits for all cases and 32 bits for some cases
#define div32(x,y,z) ((((unsigned long long)((unsigned long)(x)))*((unsigned long long)((unsigned long)(y))))>>(z))

// Divide by 10 (valid for 32 bits)
#define div10_32(x) div32(x,0xcccccccd,35)
#define rem10_32(x) ((x)-10*div10_32(x))


void led7seg_init(int useRB03){
    int i;
    // Digital input setting for RB0-3
    TRISBSET=ANSELBCLR=useRB03&0x0f;
	// Digital output to RB4-7
	TRISBCLR=0x00F0;
    // Digital input from RB8-15.
    // Note that this setting will be changed upon interruption.
    // L output when digital output to RB8-15
    TRISBSET=LATBCLR=0xFF00;
    // Timer 1 settings
	PR1=TIMER1COUNT-1;
	TMR1=0;
	T1CON=0x0000; // The simplest mode
	// Timer1 interrupt: priority 4
	IPC2bits.T1IP=4;
	IPC2bits.T1IS=0;
	IFS0bits.T1IF=0;
	IEC0bits.T1IE=1;
    // Blank output
    for(i=0;i<4;i++) g_leddata[i]=0;
    // Start timer
    T1CONbits.ON=1;
    // Wait for a display cycle to initialize key data.
    for(i=0;i<32;i++) asm("wait");
}

void __ISR(_TIMER_1_VECTOR, IPL4SOFT) timer1Int(void){ 
	static int t1counter=0;
	int whichled=t1counter&0x03;
	int whichseg=t1counter>>2;

    // Key input fist.
    // Key data is taken for the previous LATB0-7 output
    // Note: data will be 1 when L input and 0 when H input
    if (whichled==0x00) {
        g_keydata[(whichseg-1)&0x07]=(PORTB & 0x0f)^0x0f;
    }
    
	// Set L for RB8-15 always
    if (whichled==0x00) {
        TRISBSET=0xFF00;
        TRISBCLR=1<<(whichseg+8);
    }
	
	// Set H for RB4-7 when ON
	LATBCLR=0x00F0;
	if (g_leddata[whichled]&(1<<whichseg)) {
        LATBSET=1<<(whichled+4);
	}
     
	t1counter++;
	t1counter&=0x1f;
	IFS0bits.T1IF=0;
}

void led7seg_hex(int pos, char num){
	g_leddata[pos & 0x03]=g_dec2led[num & 0x0f]|((num&0x10)?0x01:0);
}

void led7seg_point(int pos){
	g_leddata[pos & 0x03]|=0x80;
}

void led7seg_dec4(int num){
    int i;
    if (999<num) {
        i=div10_32(num);
        led7seg_hex(3,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(2,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(1,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(0,num-i*10);
    } else if (99<num) {
        i=div10_32(num);
        led7seg_hex(3,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(2,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(1,num-i*10);
        g_leddata[0]=0;
    } else if (9<num) {
        i=div10_32(num);
        led7seg_hex(3,num-i*10);
        num=i;
        i=div10_32(num);
        led7seg_hex(2,num-i*10);
        g_leddata[1]=0;
        g_leddata[0]=0;
    } else {
        i=div10_32(num);
        led7seg_hex(3,num-i*10);
        g_leddata[2]=0;
        g_leddata[1]=0;
        g_leddata[0]=0;        
    }
}