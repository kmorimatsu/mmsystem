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
#include "led7seg.h"

// Include optional header(s)
#include "adc.h"
#include "i2c.h"

void main(){
	// Initialize MM System
	mm_init();

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
