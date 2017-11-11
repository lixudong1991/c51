//#include<reg52.h>
#include<STC12C5A60S2.H>
#include"common.h"

#define LED P0
#define KEY16 P1
#define LEDBIT P2

sbit p22=LEDBIT^2;
sbit p23=LEDBIT^3;
sbit p24=LEDBIT^4;
void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	uint8 j=8;
	for(;j;j--)
	{
	    uint8 n=(v%m-sum)/(m/10);
	   	p22=(j-1)&1;
		p23=((j-1)&2)>>1;
		p24=((j-1)&4)>>2;
		if(j==8||sum<v)
		{
		   LED=~number[n];	
		}else {
		   LED=~number[16];
		}
		waitus(20);
		LED=0;
		sum = v%m;
		m = m*10; 
	}
}

//·äÃùÆ÷ 
sbit beep=P2^7;
void beepfun()
{
	beep=1;
	waitus(3);
	beep=0;
	waitus(25);
}

char getv(uint8 v)
{
	switch(v)
	{
		case 7:
			return 3;
		case 11:
		 	return 2;
		case 13:
			return 1;
		case 14:
		 	return 0;
	}
	return 0;
}


uint8 keydown(uint8* ch)
{
	uint8 isdown=0;
	uint8 n=0;
	KEY16=0xf0;
	if(KEY16!=0xf0)
	{
	    waitus(5000);	   
		if(KEY16!=0xf0)
		{
		   uint8 x=getv(KEY16>>4);
		   KEY16=0x0f;
		   waitus(100);
		   if(KEY16!=0x0f)
		   {
		      uint8 y=getv(KEY16);
			  *ch =x+y*4;		  		
		   }
		   isdown=1;	   
		   while(n++<800&&KEY16!=0x0f)
		   {
			  beepfun();	 
		   }	   		                     
		}		
	}
	return isdown;
}


int main()
{
	uint8 c=0;	
	uint32 val=0;
	uint8 i=0;
	while(TRUE)
	{
		uint8 isd=keydown(&c);	
		if(isd)
		{
			if(c<10&&i<8)
			{				
				if(c!=0||i!=0)
				{
					 val=val*10+c;
					 i++;
				}							
			}
			else if(i==8)
			{
				i=1;
				val=c;
			}
			else
			{
			   val=0;
			   i=0;	   
			}			
		} 
		DigDisplay(val);
	}
}