#include <STC12C.h>
#include"main.h"
#define LED P0
#define LEDBIT P2

sbit p22=LEDBIT^2;
sbit p23=LEDBIT^3;
sbit p24=LEDBIT^4;
sbit key=P3^2;

void DigDisplay(uint32 v);
void Int0_init();



void main()
{

  uint32 v=0;
  uint8 i=0;

  Int0_init();

  while(TRUE)
  {	
	for(i=0;i<200;i++)
	DigDisplay(v);
	v++;
  }
}
void Int0_init()
{
	IT0=1;
	EX0=1;
	EA=1;
}
void Int0_Routine()interrupt 0
{
		waitus(1000);
		if(key==0)
		{
			DigDisplay(8794561);
		}

} 



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