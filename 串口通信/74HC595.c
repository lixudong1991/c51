#include"74HC595.h"

void write595(uint8 v,uint8 v1)
{
   uint8 i=0,j=0x80; 
   for(i=0;i<8;i++)
   {  
   	    SER=v>>7;
	    v<<=1;
		SCK=0;
		_nop_();
		_nop_();	
		SCK=1;		
   } 
   for(i=0;i<8;i++)
   {  
   	    SER=v1>>7;
	    v1<<=1;
		SCK=0;
		_nop_();
		_nop_();	
		SCK=1;		
   }
   RCK=0;
   _nop_();
   _nop_();
   RCK=1;
}