#include"dig.h"

uint32 v=0;

void T_init()
{
	TMOD|=0x51;
	AUXR|=0x80;//����stc12c5a60s2 ��T0��ʱ��Ϊ1T,Ĭ�Ϻ�51һ����12T

	TL0=0xA0; //��ʱ1ms  ʱ����㹫ʽ ��ʱxms ��ʱ��=65536-x*(1000/��������(��λus)); TL0=0x18;	TH0=0xFC;
	TH0=0x15;

	ET0=1;
	ET1=1;
	EA=1;
	TR0=1;	
	TR1=1;	
}
void T0_Routine()interrupt 1
{
	static uint16 i=0;
	TL0=0xA0;
	TH0=0x15;
	i++;
	if(i==200)
	{
		i=0;
		TR0=0;	
		TR1=0;
	}	
}
void T1_Routine()interrupt 3
{
	v+=65536;
}

int main()
{
   uint32 m=0;  	 
   T_init();
   while(TRUE)
   {  
   		if(TR0==0)
		{
		 	v+=TL1;
		 	v+=(TH1<<8);
			m=v;
			v=0;
			TL1=0;
			TH1=0;
			TR0=1;
			TR1=1;		 
		}
   	  	  
		DigDisplay(m);				   	
   }
} 
