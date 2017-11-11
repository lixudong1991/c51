#include<reg52.h>
#include<intrins.h>
#include"common.h"

//led流水灯
void ledfun()
{
   	char i=0;
	P0=0x1;
	for(i=0;i<7;i++)
	{
		waitms(550);
		P0=_crol_(P0,1);		
	}
	for(i=0;i<7;i++)
	{
		waitms(550);
		P0=_cror_(P0,1);
	}
}			

//蜂鸣器 
sbit beep=P1^0;
void beepfun()
{
	beep=1;
	waitus(5);
	beep=0;
	waitus(15);
}

//继电器
sbit relay=P1^4;
void elecrelay()
{
	relay=0;
	waitms(600);
	relay=1;
	waitms(600);
}

//静态数码管  数组分别对应0123456789abcdef数组最后一位是无显示
char code number[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xff};
void shownumber()
{	
	char i;
	for(i=0;i<17;i++)
	{
	   P0=number[i];  //共阳极
	   P1=~number[i];  //共阴极
	   waitms(1000);
	}
}
sbit p=P1^0;
//直流电机
void dianji()
{	 
	 P=1;
	 waitms(10000);
	 p=0;
}
int main()
{
	dianji();
	while(TRUE)
	{			
	}		
}  						           
