#include<reg52.h>
#include"common.h"

sbit p22=P2^2;
sbit p23=P2^3;
sbit p24=P2^4;

//动态数码管显示
void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	char j=7;
	while (sum!=v)
	{
		char n=(v%m-sum)/(m/10);
	   	p22=j&1;
		p23=(j&2)>>1;
		p24=(j&4)>>2;	
		P1=~number[n];
		waitus(50);
		P1=0;
		sum = v%m;
		m = m*10; 
		j--;		
	}
	
}
int main()
{
	  P1=0;
	  while(TRUE)
	  {	  
	  	 uint32 j=0;
		 for(j=0;j<2147483647;j++)
		 {	  
		 	 char i=100;
			 for(;i;i--)  
			 DigDisplay(j);
			
		 }
	  }
}