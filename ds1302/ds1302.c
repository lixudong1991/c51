#include "ds1302.h"
#include <intrins.h>
sbit sclk=SCLK;
sbit dsio=DSIO;
sbit dsce=DSCE;

void writeds1302(uint8 contr,uint8 dat)
{
	uint8 i=0,a=0x01;
	dsce=0;
	_nop_();
	sclk=0;
	_nop_();
	dsce=1;
	_nop_();
	for(i=0;i<8;i++)
	{
		dsio=a&contr;
		sclk=1;
		_nop_();
		sclk=0;
		_nop_();
		contr>>=1;	
	}
	for(i=0;i<8;i++)
	{
		dsio=a&dat;
		sclk=1;
		_nop_();
		sclk=0;
		_nop_();
		dat>>=1;	
	}
	dsce=0;
	_nop_();
}
uint8 reads1302(uint8 contr)
{
	uint8 i=0,a=0x01,ret=0x00,tem=0x00;
	dsce=0;
	_nop_();
	sclk=0;
	_nop_();
	dsce=1;
	_nop_();
	for(i=0;i<8;i++)
	{
		dsio=a&contr;
		sclk=1;
		_nop_();
		sclk=0;
		_nop_();
		contr>>=1;	
	}
	_nop_();
	for(i=0;i<8;i++)
	{
		tem=dsio;
		tem<<=i;
		ret|=tem;
		sclk=1;
		_nop_();
		sclk=0;
		_nop_();
	}
	dsce=0;
	_nop_();
	sclk=1;
	_nop_();
	dsio=0;
	_nop_();
	dsio=1;
	_nop_();
	return ret;
}
uint8 bton(uint8 bcd)
{
	uint8 tem=0;
	tem=bcd&0x0f;
	return tem+(bcd>>4)*10;
}
uint8 ntob(uint8 val)
{
	uint8 tem=val/10;
	tem<<=4;
	return tem+val%10;
}
void write1302time(uint32 time)
{
	uint8 hour=time/3600;
	uint8 min=(time%3600)/60;
	uint8 sec=time%60;
	writeds1302(0x8e,0x00);
	writeds1302(0x80,ntob(sec));
	writeds1302(0x82,ntob(min));
	writeds1302(0x84,ntob(hour));
	writeds1302(0x8e,0x80);
}
uint32 read1302time()
{
	uint32 hour=0;
	uint32 min=0;
	uint32 sec=0;
	sec=bton(reads1302(0x81));
	min=bton(reads1302(0x83));
	hour=bton(reads1302(0x85));
	return hour*10000+min*100+sec;
}