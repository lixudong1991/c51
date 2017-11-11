#include<STC12C5A60S2.H>
#include<intrins.h>
#include"common.h"
#define LED P0
sbit SCK=P3^6;
sbit IN_data=P1^7;
sbit SH_LD=P1^6;

uint8 read74hc165()
{
	uint8 val=0;
	uint8 i=0;
	SH_LD=0;
	_nop_();
	SH_LD=1;
	_nop_();	
	for(i=0;i<8;i++)
	{
		val=val<<1;
		SCK=0;
		_nop_();
		val|=IN_data;
		SCK=1;
	}
	return val;
}

int main()
{
	uint8 v=0;
	LED=0;
	while(1)
	{
	   if((v=read74hc165())!=0xff)
	   {
		  LED=~v;		  
	   }
	}
}  