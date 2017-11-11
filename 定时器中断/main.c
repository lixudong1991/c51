//#define LCD1602_DISPLAY
#ifdef LCD1602_DISPLAY

#include<stdio.h>
#include<string.h>
#include"lcd1602.h"

#else

#include"dig.h"

#endif

uint32 sec=0;

void T0_init()
{
	TMOD|=0x01;
	AUXR|=0x80;//设置stc12c5a60s2 的T0计时器为1T,默认和51一样是12T
	TL0=0x20; //计时1ms  时间计算公式 计时xms 则时间=65536-x*(1000/机器周期(单位us)); TL0=0x18;	TH0=0xFC;
	TH0=0xD1;
	ET0=1;
	EA=1;
	TR0=1; 	
}
void T0_Routine()interrupt 1
{
	static uint16 i=0;
	TL0=0x20;
	TH0=0xD1;
	i++;
	if(i==1000)
	{
		i=0;
		sec++;
	}	
}


int main()
{
#ifdef LCD1602_DISPLAY
   uint8 buff[32]; 
   uint32 j=0;
   lcd_init();
   lcd_print("0");    
#endif 
 
   T0_init();  
   	 
   while(TRUE)
   {  

#ifdef LCD1602_DISPLAY	
		if(j!=sec){			
			memset(buff,0,sizeof(buff));			 
	   		sprintf(buff,"Time: %d",);
	   		lcd_print(buff);
			j=sec;
		}
#else
		DigDisplay(sec);
#endif
							   	
   }
} 
