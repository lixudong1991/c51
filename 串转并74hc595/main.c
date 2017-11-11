//#include<STC12C.H>
#include<intrins.h>
#include<reg52.h>
#include"main.h"


sbit SER=P3^4;
sbit RCK=P3^5;
sbit SCK=P3^6;

void write595(uint8 v)
{
   uint8 i=0,j=0x80;
   
   for(i=0;i<8;i++)
   {  
   		SER=j&v; //SER=v>>7;
		j>>=1;	// v<<=1;
		SCK=0;
		_nop_();
		_nop_();	
		SCK=1;		
   } 
   RCK=0;
   _nop_();
   _nop_();
   RCK=1;
}
//ledÁ÷Ë®µÆ
void ledfun()
{
   	uint8 i=0,j=1;
	for(i=0;i<7;i++)
	{
		write595(j);
		waitms(1500);
		j=_crol_(j,1);		
	}
	for(i=0;i<7;i++)
	{
		write595(j);
		waitms(1500);
		j=_cror_(j,1);
	}
}	
int main()
{
	while(TRUE)
	{
		ledfun();	
	}
}