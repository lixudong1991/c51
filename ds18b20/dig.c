#include"dig.h"
sbit dig_a=DIG_A;
sbit dig_b=DIG_B;
sbit dig_c=DIG_C;

char code number[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6, 0x77, 0x7c, 0x39 , 0x5e, 0x79, 0x71,0x00};

void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	uint8 j=8;
	for(;j;j--)
	{
	  uint8 n=(v%m-sum)/(m/10);
	  dig_a=(j-1)&1;
		dig_b=((j-1)&2)>>1;
		dig_c=((j-1)&4)>>2;
		if(j==8||sum<v)
		{
		   LED=number[n];	
		}else {
		   LED=number[16];
		}
		waitus(100);
		LED=0;
		sum = v%m;
		m = m*10; 
	}
}