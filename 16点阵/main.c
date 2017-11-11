//#include<STC12C.H>
#include<intrins.h>
#include<reg52.h>
#include"main.h"

sbit SER=P3^4;
sbit RCK=P3^5;
sbit SCK=P3^6;
void write595(uint8 dat1,uint8 dat2,uint8 dat3,uint8 dat4)
{
	uint8 a;
	SCK = 1;
	RCK = 1;
	for(a=0;a<8;a++)		 //发送8位数
	{
		SER = dat1 >> 7;		 //从最高位开始发送
		dat1 <<= 1;

		SCK = 0;			 //发送时序
		_nop_();
		_nop_();
		SCK = 1;	
	}

	for(a=0;a<8;a++)		 //发送8位数
	{
		SER = dat2 >> 7;		 //从最高位开始发送
		dat2 <<= 1;

		SCK = 0;			 //发送时序
		_nop_();
		_nop_();
		SCK = 1;	
	}

	for(a=0;a<8;a++)		 //发送8位数
	{
		SER = dat3 >> 7;		 //从最高位开始发送
		dat3 <<= 1;

		SCK = 0;			 //发送时序
		_nop_();
		_nop_();
		SCK = 1;	
	}

	for(a=0;a<8;a++)		 //发送8位数
	{
		SER = dat4 >> 7;		 //从最高位开始发送
		dat4 <<= 1;
		SCK = 0;			 //发送时序
		_nop_();
		_nop_();
		SCK = 1;	
	}  

	RCK = 0;
	_nop_();
	_nop_();
	RCK = 1;
} 
	

void led16out(uint8 word[],uint8 length)
{
		 uint8 j;
		 if(length!=32)
		 {
		    return;	
		 }
		 for(j=0;j<16;j++)
	     {		 	
			write595(ledwei[j+16],ledwei[j],word[j+16],word[j]);
			waitus(10);
		 } 
}
uint8 code ledword[32]={
0x08,0x04,0xC3,0x12,0x26,0x8A,0xA2,0xAA,0xA4,0xA3,0x22,0x26,0xEA,0x02,0x02,0x00,
0x00,0x00,0xFF,0x00,0x00,0x3F,0x24,0x24,0x24,0x3F,0x00,0x80,0xFF,0x00,0x00,0x00
};
int main()
{
	while(TRUE)
	{	  
		 led16out(ledword,32);
	}
}