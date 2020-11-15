/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

#ifndef ADC_H
#define	ADC_H

/*
 * void adc_init(int used_adc);
 * 
 * Initialize Analog Digital converter unit.
 * 
 * Define using ADC # (AN#) in used_adc.
 * 
 * For example, if AN0 (RA0) and AN11 (RB3) are used as analog source,
 * used_adc=(1<<0)|(1<<11)=0x0801
 * 
 */

void adc_init(int used_adc);

/*
 * unsigned int read_adc(int adc_num);
 * 
 * Read ADC data as 12 bit integer from defined AN#.
 * 
 * For example, to read from AN11 (RB3), adc_num=11.
 * 
 */

unsigned int adc_read(int adc_num);


#endif	/* ADC_H */

