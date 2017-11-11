#include "common.h"

void waitus(uint32 v)	  //ºÁÃë
{	
	while(v--);
}

void delay500us()   
{
    uint8 a,b;
    for(b=18;b>0;b--)
        for(a=152;a>0;a--);
}




