#include"dig.h"
#include"74HC595.h"
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

uint8 state[4][2]=
{
 {~0x85,0x02},
 {~0x45,0x02},
 {~0x32,0x01},
 {~0x2a,0x01}
};
int main()
{
   uint32 index=0,sum=30;	 
   T0_init();  
   while(TRUE)
   {  
   	    write595(state[index%4][0],state[index%4][0]);
	    while(sec!=sum){
		   DigDisplay(60-sec%60);
		}
		sum+=30;
		index++; 										   	
   }
} 
