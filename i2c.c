#include <xc.h>
#include "i2c.h"

/*
	i2c_error_val contains number errors occured (# of NAK signals).
*/
static int i2c_error_val;

void _i2c_wait(int times){
	asm volatile(".set noreorder");
    asm volatile("i2cloop:");
    asm volatile("bne $a0,$zero, i2cloop");
    asm volatile("addiu $a0,$a0,-1");
}
/*
	i2c_init(): Initialize I2C peripheral.
		1. set digital mode.
		2. all input mode.
		3. Output L when ourput mode.
*/
void i2c_init(){
	// Use digital but not analog
	I2C_SCL_ANSEL_CLR=I2C_SCL_MASK;
	I2C_SDA_ANSEL_CLR=I2C_SDA_MASK;
	// All input first
	I2C_SCL_TRIS_SET=I2C_SCL_MASK;
	I2C_SDA_TRIS_SET=I2C_SDA_MASK;
	// Latch is always L
	I2C_SCL_LAT_CLR=I2C_SCL_MASK;
	I2C_SDA_LAT_CLR=I2C_SDA_MASK;
	// Weak pull up
	I2C_SCL_CNPU_SET=I2C_SCL_MASK;
	I2C_SDA_CNPU_SET=I2C_SDA_MASK;
}

int i2c_write(char addr, char* data, int len){
	int i;
	i2c_error_val=0;
	_i2c_start();
	i2c_error_val+=_i2c_write(addr<<1);
	for(i=0;i<len;i++){
		i2c_error_val+=_i2c_write(data[i]);
	};
	_i2c_stop();
	return i2c_error_val;
}
char i2c_read(char addr, char* data, int len){
	int i;
	_i2c_start();
	i2c_error_val=_i2c_write((addr<<1)+1);
	for(i=0;i<len;i++){
		data[i]=_i2c_read(i<len-1 ? 0:1);
	};
	_i2c_stop();
	return i2c_error_val;
}
int i2c_write8(char addr, char data){
	int dataa[1];
	dataa[0]=data;
	return i2c_write(addr,(char*)dataa,1);
}
char i2c_read8(char addr){
	int dataa[1];
	i2c_read(addr,(char*)dataa,1);
	return dataa[0];
}
int i2c_error(){
	return i2c_error_val;
}
void _i2c_start(){
	i2c_wait();
	i2c_wait();
	I2C_SDA_TRIS_SET=I2C_SDA_MASK;
	i2c_wait();
	I2C_SCL_TRIS_SET=I2C_SCL_MASK;
	i2c_wait();
	I2C_SDA_TRIS_CLR=I2C_SDA_MASK;
	i2c_wait();
	I2C_SCL_TRIS_CLR=I2C_SCL_MASK;
	i2c_wait();
}
void _i2c_stop(){
	I2C_SDA_TRIS_CLR=I2C_SDA_MASK;
	i2c_wait();
	I2C_SCL_TRIS_SET=I2C_SCL_MASK;
	i2c_wait();
	i2c_wait();
	I2C_SDA_TRIS_SET=I2C_SDA_MASK;
	i2c_wait();
	i2c_wait();
}

/*
	_i2c_write_bit(): Send bit data
	Sequence contain 3 parts.
	1. Set DAT and wait
	2. Raise CLK and 2xwait. Wait until CLK will be high.
	3. Fall CLK and wait
*/

#define _i2c_write_bit(bitdata) do {\
		if (bitdata) I2C_SDA_TRIS_SET=I2C_SDA_MASK; else I2C_SDA_TRIS_CLR=I2C_SDA_MASK;\
		i2c_wait();\
		I2C_SCL_TRIS_SET=I2C_SCL_MASK;\
		i2c_wait();\
		while(!(I2C_SCL_PORT & I2C_SCL_MASK));\
		i2c_wait();\
		I2C_SCL_TRIS_CLR=I2C_SCL_MASK;\
		i2c_wait();\
	} while(0)

/*
	_i2c_read_bit(): Receive bit data
	Sequence contain 4 parts.
	1. Set DAT to H and wait
	2. Raise CLK and 2xwait. Wait until CLK will be high.
	4. Read DAT and wait
*/

#define _i2c_read_bit(bitdata) do{\
		I2C_SDA_TRIS_SET=I2C_SDA_MASK;\
		i2c_wait();\
		I2C_SCL_TRIS_SET=I2C_SCL_MASK;\
		i2c_wait();\
		while(!(I2C_SCL_PORT & I2C_SCL_MASK));\
		i2c_wait();\
		bitdata=(I2C_SDA_PORT & I2C_SDA_MASK) ? 1:0;\
		I2C_SCL_TRIS_CLR=I2C_SCL_MASK;\
		i2c_wait();\
	} while(0)

char _i2c_write(char data){
	char ack;
	_i2c_write_bit(data&0x80);
	_i2c_write_bit(data&0x40);
	_i2c_write_bit(data&0x20);
	_i2c_write_bit(data&0x10);
	_i2c_write_bit(data&0x08);
	_i2c_write_bit(data&0x04);
	_i2c_write_bit(data&0x02);
	_i2c_write_bit(data&0x01);
	_i2c_read_bit(ack);
	return ack;
}
char _i2c_read(char ack){
	char data,bitdata;
	_i2c_read_bit(bitdata);
	data=bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_read_bit(bitdata);
	data=(data<<1)|bitdata;
	_i2c_write_bit(ack);
    return data;
}
