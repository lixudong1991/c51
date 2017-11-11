#include<reg52.h>
#include"common.h"
//按键控制8个led灯
void keyled()
{
     if(P0!=0xff)
     {  
		waitus(1000);
		if(P0!=0xff)
		{
		    P1^=~P0;                  
		}
		while(P0!=0xFF);
	 }	
}
//按键控制数字递增或递减 ,并显示在动态数码管上
sbit p22=P2^2;
sbit p23=P2^3;
sbit p24=P2^4;
void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	char j=7;
	if(v<10)
	{
	 	p22=1;
		p23=1;
		p24=1;
		P1=~number[v];
		return;	
	}
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
void keynum(uint32* num)
{
		
	if(P0!=0xff)
    {  
		waitus(1000);
		if(P0!=0xff)
		{
			char val=~P0;
			if(val%2)
			{
			   *num=*num+1;
			}else if(*num>0){
				
			   *num=*num-1;
			}	                
		}
		while(P0!=0xFF);
	}
	DigDisplay(*num);	
}
int main()
{
   uint32 v=0;
   while(TRUE)
   {  
   		keynum(&v);					
   }
}																		   