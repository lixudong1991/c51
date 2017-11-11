#include"dig.h"
char code number[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xff};

void waitus(uint32 v)	  //ºÁÃë
{	
	while(v--);
}

void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	uint8 j=8;
	for(;j;j--)
	{
	    uint8 n=(v%m-sum)/(m/10);
	   	DIG_A=(j-1)&1;
		DIG_B=((j-1)&2)>>1;
		DIG_C=((j-1)&4)>>2;
		if(j==8||sum<v)
		{
		   LED=~number[n];	
		}else {
		   LED=~number[16];
		}
		waitus(10);
		LED=0;
		sum = v%m;
		m = m*10; 
	}
}