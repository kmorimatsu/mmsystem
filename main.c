/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

#include <xc.h>
#include <sys/attribs.h>
#include "led7seg.h"
#include "adc.h"
#include "i2c.h"

// FDEVOPT
//#pragma config ALTCMP = OFF             // Alternate Comparator1 Pins Location Enable bit (Primary C1INB pin is used)
#pragma config SOSCHP = OFF             // Secondary Oscillator High Power Enable bit (SOSC oprerates in normal power mode.)
//#pragma config ALTI2C = OFF             // Alternate I2C1 Pins Location Enable bit (Primary I2C1 pins are used)
//#pragma config USERID = USERID          // User ID bits (User ID bits)

// FICD
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config ICS = PGx1               // ICE/ICD Communication Channel Selection bits (Communicate on PGEC1/PGED1)

// FPOR
#pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware; SBOREN bit disabled)
#pragma config RETVR = OFF              // Retention Voltage Regulator Enable bit (Retention regulator is disabled)
#pragma config LPBOREN = ON             // Low Power Brown-out Enable bit (Low power BOR is enabled, when main BOR is disabled)

// FWDT
#pragma config SWDTPS = PS1048576       // Sleep Mode Watchdog Timer Postscale Selection bits (1:1048576)
#pragma config FWDTWINSZ = PS25_0       // Watchdog Timer Window Size bits (Watchdog timer window size is 25%)
#pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Watchdog timer is in non-window mode)
#pragma config RWDTPS = PS1048576       // Run Mode Watchdog Timer Postscale Selection bits (1:1048576)
#pragma config RCLKSEL = LPRC           // Run Mode Watchdog Timer Clock Source Selection bits (Clock source is LPRC (same as for sleep mode))
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bit (WDT is disabled)

// FOSCSEL
// Internal 8 MHz oscilattor is used as SYSCLK
#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
//#pragma config FRCDIV = 0               // FRC divided by 1 (default setting)
#pragma config PLLSRC = FRC             // System PLL Input Clock Selection bit (FRC oscillator is selected as PLL reference input on device reset)
#pragma config SOSCEN = OFF             // Secondary Oscillator Enable bit (Secondary oscillator (SOSC) is disabled)
#pragma config IESO = OFF               // Two Speed Startup Enable bit (Two speed startup is disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Selection bit (Primary oscillator is disabled)
#pragma config OSCIOFNC = OFF           // System Clock on CLKO Pin Enable bit (OSCO pin operates as a normal I/O)
#pragma config SOSCSEL = ON             // Secondary Oscillator External Clock Enable bit (External clock is connected to SOSCO pin (RA4 and RB4 are controlled by I/O port registers))
#pragma config FCKSM = CSECME           // Clock Switching and Fail-Safe Clock Monitor Enable bits (Clock switching is enabled; Fail-safe clock monitor is enabled)

void main(){
	// Enable interrupt
	__builtin_enable_interrupts();

    // Initializing 7 seg LED system. 
    led7seg_init(0x00); // No key input
    //led7seg_init(0x01); // Use only RB0 for key input
    //led7seg_init(0x08); // Use only RB3 for key input
    //led7seg_init(0x0f); // Use all RB0-3 for key input

    // Example of initializing ADC. RB0 (AN2) and RB1 (AN3) are used.
    //adc_init((1<<2)|(1<<3));
    
    // Initialize I2C if required
    //i2c_init();

    // Infinite loop until reset switch will be pressed
    while(1){
        led7seg_dec4(1234);
        asm volatile("wait");
    }
}
