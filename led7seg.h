/*
   This program is provided under the LGPL license ver 2.1
   MM system, written by Katsumi.
   http://hp.vector.co.jp/authors/VA016157/
   kmorimatsu@users.sourceforge.jp
*/

#ifndef LED7SEG_H
#define	LED7SEG_H

/*
 * led7seg_init(int useRB03);
 * 
 * Initializes 7 seg LED & key input system
 * Define which RB0-RB3 is/are used for key input.
 * If onlt RB0 is used, usedRB03=0x01;
 * If onlt RB3 is used, usedRB03=0x08;
 * If RB0-RB3 are all used, usedRB03=0x0f;
 * 
 */
void led7seg_init(int useRB03);

/*
 * led7seg_hex(int pos, char num);
 * 
 * Shows hexadecimal number at indicated position.
 * If bit 8 is set (number more than 15) then point will be also bright.
 * 
 */
void led7seg_hex(int pos, char num);

/*
 * led7seg_point(int pos);
 * 
 * Point at indicated position will be bright.
 * 
 */
void led7seg_point(int pos);

/*
 * led7seg_dec(int num);
 * 
 * Show decimal value (0-9999)
 * 
 */
void led7seg_dec4(int num);

/*
 * unsigned char g_keydata[8];
 * 
 * Containing key data fetched from RB0-3
 * See KEYxxON macros to know which data corresponds which bit of this data
 * 
 */
extern volatile unsigned char g_keydata[8];

/*
 * unsigned char g_leddata[4];
 * 
 * Containing 7 seg LED data to show.
 * 
 */
extern volatile unsigned char g_leddata[4];

/*
 * KEY0ON - KEY31ON macros
 * 
 * There can be up to 32 keys.
 * KEY0-KEY7   are read from RB0
 * KEY8-KEY15  are read from RB1
 * KEY16-KEY23 are read from RB2
 * KEY24-KEY31 are read from RB3
 */

#define KEY0ON (g_keydata[0]&0x01)
#define KEY1ON (g_keydata[1]&0x01)
#define KEY2ON (g_keydata[2]&0x01)
#define KEY3ON (g_keydata[3]&0x01)
#define KEY4ON (g_keydata[4]&0x01)
#define KEY5ON (g_keydata[5]&0x01)
#define KEY6ON (g_keydata[6]&0x01)
#define KEY7ON (g_keydata[7]&0x01)
#define KEY8ON (g_keydata[0]&0x02)
#define KEY9ON (g_keydata[1]&0x02)
#define KEY10ON (g_keydata[2]&0x02)
#define KEY11ON (g_keydata[3]&0x02)
#define KEY12ON (g_keydata[4]&0x02)
#define KEY13ON (g_keydata[5]&0x02)
#define KEY14ON (g_keydata[6]&0x02)
#define KEY15ON (g_keydata[7]&0x02)
#define KEY16ON (g_keydata[0]&0x04)
#define KEY17ON (g_keydata[1]&0x04)
#define KEY18ON (g_keydata[2]&0x04)
#define KEY19ON (g_keydata[3]&0x04)
#define KEY20ON (g_keydata[4]&0x04)
#define KEY21ON (g_keydata[5]&0x04)
#define KEY22ON (g_keydata[6]&0x04)
#define KEY23ON (g_keydata[7]&0x04)
#define KEY24ON (g_keydata[0]&0x08)
#define KEY25ON (g_keydata[1]&0x08)
#define KEY26ON (g_keydata[2]&0x08)
#define KEY27ON (g_keydata[3]&0x08)
#define KEY28ON (g_keydata[4]&0x08)
#define KEY29ON (g_keydata[5]&0x08)
#define KEY30ON (g_keydata[6]&0x08)
#define KEY31ON (g_keydata[7]&0x08)

#endif	/* LED7SEG_H */

