#include"dig.h"

#define KEY16 P1
#define MODE_1T

#define SYSCLK  11059200
#define BAUD  4800



uint8 recvdata=0;
void UART_init()
{
	uint32 tem=BAUD;
	TMOD|=0x20;
	SCON|=0x50;
	PCON|=0x80;
#ifdef MODE_1T
	AUXR|=0X40;
	TL1=TH1=256-((SYSCLK*(1<<(PCON>>7)))/(32*tem)); 
#else
	TL1=TH1=256-((SYSCLK*(1<<(PCON>>7)))/(32*tem*12)); 
#endif    
	TR1=1;
	ES=1;
	EA=1;			
} 
void UART_Routine()interrupt 4
{
     if(RI)
	 {
	   recvdata=SBUF;
	   RI=0; 
	 }
	 if(TI)
	 {
	   TI=0;
	 }	 	 
} 
uint8 keydown(uint8* ch);
int main()
{ 
   uint8 c=0;
   UART_init();
   while(TRUE)
   { 
   		if(keydown(&c)) 
		{
		  SBUF=c+0x30;
		  recvdata=c;
		}
		DigDisplay(recvdata);				   	
   }
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
		   while(n++<800&&KEY16!=0x0f);	   		                     
		}		
	}
	return isdown;
}

