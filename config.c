/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

// Include required headers
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"

/*
	Configures of PIC32MM0064GPL028 follow
*/

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
#pragma config PLLSRC = FRC             // System PLL Input Clock Selection bit (FRC oscillator is selected as PLL reference input on device reset)
#pragma config SOSCEN = OFF             // Secondary Oscillator Enable bit (Secondary oscillator (SOSC) is disabled)
#pragma config IESO = OFF               // Two Speed Startup Enable bit (Two speed startup is disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Selection bit (Primary oscillator is disabled)
#pragma config OSCIOFNC = OFF           // System Clock on CLKO Pin Enable bit (OSCO pin operates as a normal I/O)
#pragma config SOSCSEL = ON             // Secondary Oscillator External Clock Enable bit (External clock is connected to SOSCO pin (RA4 and RB4 are controlled by I/O port registers))
#pragma config FCKSM = CSECME           // Clock Switching and Fail-Safe Clock Monitor Enable bits (Clock switching is enabled; Fail-safe clock monitor is enabled)

/*
	Clock settings by RC follow
*/

#if MM_SYSTEM_CLOCK==500000
	#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
	#define MM_SPLLCON 0x10000
	#define MM_OSCCON 0x4000000
#endif
#if MM_SYSTEM_CLOCK==1000000
	#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
	#define MM_SPLLCON 0x10000
	#define MM_OSCCON 0x3000000
#endif
#if MM_SYSTEM_CLOCK==2000000
	#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
	#define MM_SPLLCON 0x10000
	#define MM_OSCCON 0x2000000
#endif
#if MM_SYSTEM_CLOCK==4000000
	#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
	#define MM_SPLLCON 0x10000
	#define MM_OSCCON 0x1000000
#endif
#if MM_SYSTEM_CLOCK==8000000
	#pragma config FNOSC = FRCDIV           // Internal Fast RC (FRC) Oscillator divided by FRCDIV<2:0> bits (FRCDIV)
	#define MM_SPLLCON 0x10000
	#define MM_OSCCON 0x00
#endif
#if MM_SYSTEM_CLOCK==12000000
	#pragma config FNOSC = PLL              //Oscillator Selection bits->Primary or FRC oscillator with PLL
	#define MM_SPLLCON 0x1010080
	#define MM_OSCCON 0x101
#endif
#if MM_SYSTEM_CLOCK==16000000
	#pragma config FNOSC = PLL              //Oscillator Selection bits->Primary or FRC oscillator with PLL
	#define MM_SPLLCON 0x80
	#define MM_OSCCON 0x101
#endif
#if MM_SYSTEM_CLOCK==24000000
	#pragma config FNOSC = PLL              //Oscillator Selection bits->Primary or FRC oscillator with PLL
	#define MM_SPLLCON 0x10080
	#define MM_OSCCON 0x100
#endif

void SYSTEM_RegUnlock(void){
    SYSKEY = 0x0; //write invalid key to force lock
    SYSKEY = 0xAA996655; //write Key1 to SYSKEY
    SYSKEY = 0x556699AA; //write Key2 to SYSKEY
}
void SYSTEM_RegLock(void){
   SYSKEY = 0x00000000; 
}

void mm_init(void){
	// Clock setting
	SYSTEM_RegUnlock();
	SPLLCON=MM_SPLLCON;
	OSCCON=MM_OSCCON;
	SYSTEM_RegLock();

	// Enable interrupt
	__builtin_enable_interrupts();
}
