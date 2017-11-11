#include"i2c.h"
sbit scl=SCL;
sbit sda=SDA;

void startmg()
{
	sda=1;
	delay10us();
	scl=1;
	delay10us();
	sda=0;
	delay10us();
	scl=0;
	delay10us();
	
}
void stopmg()
{
	sda=0;
	delay10us();
	scl=1;
	delay10us();
	sda=1;
	delay10us();
}


uint8 i2cwriteByte(uint8 dat)
{
	uint8 j=0,i=0;
	
	for(i=0;i<8;i++)
	{
        sda=dat>>7;
        dat<<=1;
		scl=1;
		delay10us();
		scl=0;
		delay10us();
	}
	scl=1;
	delay10us();
	sda=1;
	delay10us();
	while(sda&&j++<2000);
	scl=0;
	delay10us();
	return j<2000;
}
uint8 i2creadByte()
{
	uint8 i=0,dat=0;
	sda=1;
	delay10us();
	for(i=0;i<8;i++)
	{
		scl=1;
		delay10us();
		dat<<=1;
		dat|=sda;
		delay10us();
		scl=0;
		delay10us();
	}	
	return dat;
}

uint8 writei2c(uint8 addr,uint8 dat)
{
	startmg();
	if(!i2cwriteByte(0xa0))
	{
		return FALSE;
	}
	if(!i2cwriteByte(addr))
	{
		return FALSE;
	}
	if(!i2cwriteByte(dat))
	{
		return FALSE;
	}
	stopmg();
	return TRUE;
}
uint8 readi2c(uint8 addr)
{
	uint8 ret=0;
	startmg();
	i2cwriteByte(0xa0);
	i2cwriteByte(addr);
	startmg();
	i2cwriteByte(0xa1);
	ret=i2creadByte();
	stopmg();
	return ret;
}

