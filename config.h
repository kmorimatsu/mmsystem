#ifndef CONFIG_H
#define	CONFIG_H

/*
	Define clock here
*/

#define MM_SYSTEM_CLOCK 500000
//#define MM_SYSTEM_CLOCK 750000
//#define MM_SYSTEM_CLOCK 1000000
//#define MM_SYSTEM_CLOCK 1500000
//#define MM_SYSTEM_CLOCK 2000000
//#define MM_SYSTEM_CLOCK 3000000
//#define MM_SYSTEM_CLOCK 4000000
//#define MM_SYSTEM_CLOCK 6000000
//#define MM_SYSTEM_CLOCK 8000000
//#define MM_SYSTEM_CLOCK 12000000
//#define MM_SYSTEM_CLOCK 16000000
//#define MM_SYSTEM_CLOCK 24000000

/*
	Select SCL and SDA ports for I2C here
*/

#define I2C_SCL_RA0
//#define I2C_SCL_RA1
//#define I2C_SCL_RA2
//#define I2C_SCL_RA3
//#define I2C_SCL_RA4
//#define I2C_SCL_RB0
//#define I2C_SCL_RB1
//#define I2C_SCL_RB2
//#define I2C_SCL_RB3
//#define I2C_SCL_RC9

//#define I2C_SDA_RA0
#define I2C_SDA_RA1
//#define I2C_SDA_RA2
//#define I2C_SDA_RA3
//#define I2C_SDA_RA4
//#define I2C_SDA_RB0
//#define I2C_SDA_RB1
//#define I2C_SDA_RB2
//#define I2C_SDA_RB3
//#define I2C_SDA_RC9

/*
 Prototype(s)
 */
void mm_init(void);

#endif	/* CONFIG_H */
