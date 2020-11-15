/*
	Define system clock. If the actual clock doesn't fit, use the higher clock speed setting than actual one.
*/

#ifndef I2C_H
#define	I2C_H

//#define I2C_SYSTEM_CLOCK 500000
//#define I2C_SYSTEM_CLOCK 750000
//#define I2C_SYSTEM_CLOCK 1000000
//#define I2C_SYSTEM_CLOCK 1500000
//#define I2C_SYSTEM_CLOCK 2000000
//#define I2C_SYSTEM_CLOCK 3000000
//#define I2C_SYSTEM_CLOCK 4000000
//#define I2C_SYSTEM_CLOCK 6000000
#define I2C_SYSTEM_CLOCK 8000000
//#define I2C_SYSTEM_CLOCK 12000000
//#define I2C_SYSTEM_CLOCK 16000000
//#define I2C_SYSTEM_CLOCK 24000000

/*
	Select SCL and SDA ports here
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

#ifdef I2C_SCL_RA0
	#define I2C_SCL_MASK 0x01
	#define I2C_SCL_TRIS_CLR TRISACLR
	#define I2C_SCL_TRIS_SET TRISASET
	#define I2C_SCL_PORT PORTA
	#define I2C_SCL_LAT_CLR LATACLR
	#define I2C_SCL_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SCL_RA1
	#define I2C_SCL_MASK 0x02
	#define I2C_SCL_TRIS_CLR TRISACLR
	#define I2C_SCL_TRIS_SET TRISASET
	#define I2C_SCL_PORT PORTA
	#define I2C_SCL_LAT_CLR LATACLR
	#define I2C_SCL_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SCL_RA2
	#define I2C_SCL_MASK 0x04
	#define I2C_SCL_TRIS_CLR TRISACLR
	#define I2C_SCL_TRIS_SET TRISASET
	#define I2C_SCL_PORT PORTA
	#define I2C_SCL_LAT_CLR LATACLR
	#define I2C_SCL_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SCL_RA3
	#define I2C_SCL_MASK 0x08
	#define I2C_SCL_TRIS_CLR TRISACLR
	#define I2C_SCL_TRIS_SET TRISASET
	#define I2C_SCL_PORT PORTA
	#define I2C_SCL_LAT_CLR LATACLR
	#define I2C_SCL_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SCL_RA4
	#define I2C_SCL_MASK 0x10
	#define I2C_SCL_TRIS_CLR TRISACLR
	#define I2C_SCL_TRIS_SET TRISASET
	#define I2C_SCL_PORT PORTA
	#define I2C_SCL_LAT_CLR LATACLR
	#define I2C_SCL_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SCL_RB0
	#define I2C_SCL_MASK 0x01
	#define I2C_SCL_TRIS_CLR TRISBCLR
	#define I2C_SCL_TRIS_SET TRISBSET
	#define I2C_SCL_PORT PORTB
	#define I2C_SCL_LAT_CLR LATBCLR
	#define I2C_SCL_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SCL_RB1
	#define I2C_SCL_MASK 0x02
	#define I2C_SCL_TRIS_CLR TRISBCLR
	#define I2C_SCL_TRIS_SET TRISBSET
	#define I2C_SCL_PORT PORTB
	#define I2C_SCL_LAT_CLR LATBCLR
	#define I2C_SCL_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SCL_RB2
	#define I2C_SCL_MASK 0x04
	#define I2C_SCL_TRIS_CLR TRISBCLR
	#define I2C_SCL_TRIS_SET TRISBSET
	#define I2C_SCL_PORT PORTB
	#define I2C_SCL_LAT_CLR LATBCLR
	#define I2C_SCL_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SCL_RB3
	#define I2C_SCL_MASK 0x08
	#define I2C_SCL_TRIS_CLR TRISBCLR
	#define I2C_SCL_TRIS_SET TRISBSET
	#define I2C_SCL_PORT PORTB
	#define I2C_SCL_LAT_CLR LATBCLR
	#define I2C_SCL_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SCL_RC9
	#define I2C_SCL_MASK 0x0200
	#define I2C_SCL_TRIS_CLR TRISCCLR
	#define I2C_SCL_TRIS_SET TRISCSET
	#define I2C_SCL_PORT PORTC
	#define I2C_SCL_LAT_CLR LATCCLR
	#define I2C_SCL_ANSEL_CLR ANSELCCLR
#endif
#ifdef I2C_SDA_RA0
	#define I2C_SDA_MASK 0x01
	#define I2C_SDA_TRIS_CLR TRISACLR
	#define I2C_SDA_TRIS_SET TRISASET
	#define I2C_SDA_PORT PORTA
	#define I2C_SDA_LAT_CLR LATACLR
	#define I2C_SDA_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SDA_RA1
	#define I2C_SDA_MASK 0x02
	#define I2C_SDA_TRIS_CLR TRISACLR
	#define I2C_SDA_TRIS_SET TRISASET
	#define I2C_SDA_PORT PORTA
	#define I2C_SDA_LAT_CLR LATACLR
	#define I2C_SDA_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SDA_RA2
	#define I2C_SDA_MASK 0x04
	#define I2C_SDA_TRIS_CLR TRISACLR
	#define I2C_SDA_TRIS_SET TRISASET
	#define I2C_SDA_PORT PORTA
	#define I2C_SDA_LAT_CLR LATACLR
	#define I2C_SDA_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SDA_RA3
	#define I2C_SDA_MASK 0x08
	#define I2C_SDA_TRIS_CLR TRISACLR
	#define I2C_SDA_TRIS_SET TRISASET
	#define I2C_SDA_PORT PORTA
	#define I2C_SDA_LAT_CLR LATACLR
	#define I2C_SDA_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SDA_RA4
	#define I2C_SDA_MASK 0x10
	#define I2C_SDA_TRIS_CLR TRISACLR
	#define I2C_SDA_TRIS_SET TRISASET
	#define I2C_SDA_PORT PORTA
	#define I2C_SDA_LAT_CLR LATACLR
	#define I2C_SDA_ANSEL_CLR ANSELACLR
#endif
#ifdef I2C_SDA_RB0
	#define I2C_SDA_MASK 0x01
	#define I2C_SDA_TRIS_CLR TRISBCLR
	#define I2C_SDA_TRIS_SET TRISBSET
	#define I2C_SDA_PORT PORTB
	#define I2C_SDA_LAT_CLR LATBCLR
	#define I2C_SDA_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SDA_RB1
	#define I2C_SDA_MASK 0x02
	#define I2C_SDA_TRIS_CLR TRISBCLR
	#define I2C_SDA_TRIS_SET TRISBSET
	#define I2C_SDA_PORT PORTB
	#define I2C_SDA_LAT_CLR LATBCLR
	#define I2C_SDA_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SDA_RB2
	#define I2C_SDA_MASK 0x04
	#define I2C_SDA_TRIS_CLR TRISBCLR
	#define I2C_SDA_TRIS_SET TRISBSET
	#define I2C_SDA_PORT PORTB
	#define I2C_SDA_LAT_CLR LATBCLR
	#define I2C_SDA_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SDA_RB3
	#define I2C_SDA_MASK 0x08
	#define I2C_SDA_TRIS_CLR TRISBCLR
	#define I2C_SDA_TRIS_SET TRISBSET
	#define I2C_SDA_PORT PORTB
	#define I2C_SDA_LAT_CLR LATBCLR
	#define I2C_SDA_ANSEL_CLR ANSELBCLR
#endif
#ifdef I2C_SDA_RC9
	#define I2C_SDA_MASK 0x0200
	#define I2C_SDA_TRIS_CLR TRISCCLR
	#define I2C_SDA_TRIS_SET TRISCSET
	#define I2C_SDA_PORT PORTC
	#define I2C_SDA_LAT_CLR LATCCLR
	#define I2C_SDA_ANSEL_CLR ANSELCCLR
#endif

/*
	i2c_wait() macro spends time of 2.5 useconds.
	This corresponds to 100 kHz I2C clock.
	I2C_SYSTEM_CLOCK must be properly defined above.
*/

void _i2c_wait(int times);
#if I2C_SYSTEM_CLOCK==500000
    #define i2c_wait() asm volatile("nop")
#endif
#if I2C_SYSTEM_CLOCK==750000
    #define i2c_wait()  asm volatile("nop")
#endif
#if I2C_SYSTEM_CLOCK==1000000
    #define i2c_wait()  do { asm volatile("nop"); asm volatile("nop"); } while(0)
#endif
#if I2C_SYSTEM_CLOCK==1500000
    #define i2c_wait()  do { asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); } while(0)
#endif
#if I2C_SYSTEM_CLOCK==2000000
    #define i2c_wait()  do { asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); } while(0)
#endif
#if I2C_SYSTEM_CLOCK==3000000
    #define i2c_wait()  _i2c_wait(1)
#endif
#if I2C_SYSTEM_CLOCK==4000000
    #define i2c_wait()  _i2c_wait(2)
#endif
#if I2C_SYSTEM_CLOCK==6000000
    #define i2c_wait()  _i2c_wait(4)
#endif
#if I2C_SYSTEM_CLOCK==8000000
    #define i2c_wait()  _i2c_wait(7)
#endif
#if I2C_SYSTEM_CLOCK==12000000
    #define i2c_wait()  _i2c_wait(12)
#endif
#if I2C_SYSTEM_CLOCK==16000000
    #define i2c_wait()  _i2c_wait(17)
#endif
#if I2C_SYSTEM_CLOCK==24000000
    #define i2c_wait()  _i2c_wait(27)
#endif

/*
	void i2c_init() initializes I2C peripheral.
	I2C_SCL_xxx and I2C_SDA_xxx must be properly defined above.
*/
void i2c_init();

/*
	int i2c_write(char addr, char* data, int len) sends data to I2C slave and 
	returns error (>0 when ACK wasn't received).
	The addr is 7 bit slave address.
	The data is pointer to data array to send.
	The len is size of data in bytes.
*/
int i2c_write(char addr, char* data, int len);

/*
	char i2c_read(char addr, char* data, int len) receives data from I2C slave and 
	returns error (>0 when ACK wasn't received).
	The addr is 7 bit slave address.
	The data is pointer to data array to receive.
	The len is size of data in bytes.
*/
char i2c_read(char addr, char* data, int len);

/*
	int i2c_write8(char addr, char data) sends data to I2C slave and 
	returns error (>0 when ACK wasn't received).
	The addr is 7 bit slave address.
	The data is 8 bit data to send.
*/
int i2c_write8(char addr, char data);

/*
	char i2c_read8(char addr) receives data from I2C slave and 
	returns read value. ACK/NAK data must be taken by i2c_error().
	The addr is 7 bit slave address.
*/
char i2c_read8(char addr);

/*
	int i2c_error() returns number of errors happend in last function.
	It returns zero when no error happends (ACK was always send from slave).
*/
int i2c_error();

/*
	void _i2c_start();
	Low level function to start I2C signal start.
*/
void _i2c_start();

/*
	void _i2c_stop();
	Low level function to stop I2C signal start.
*/
void _i2c_stop();

/*
	char _i2c_write(char data);
	Low level function to send 8 bit data to slave.
	It returns acknowledge signal received from slave (1:NAK, 0:ACK).
	The data is 8 bit data to send.
	This function also support clock stretching by slave.
*/
char _i2c_write(char data);

/*
	char _i2c_read(char ack);
	Low level function to receive 8 bit data from slave.
	It returns received 8 bit data.
	The ack acknowledge to send at last (1:NAK, 0:ACK).
	This function also support clock stretching by slave.
*/
char _i2c_read(char ack);

#endif	/* I2C_H */
