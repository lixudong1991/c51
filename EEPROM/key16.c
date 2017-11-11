#include"key16.h"


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
	    waitus(3000);	   
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