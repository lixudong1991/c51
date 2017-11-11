#include "dig.h"
#include "stepmt.h"
#include "infrared.h"
uint8 va=0;
void int0_init()
{
	IT0=1;
	EX0=1;
	EA=1;
}
void int0_pro()interrupt 0
{
	getinfrdata(&va);
}	
int main()
{
	stepmotinit();
	int0_init();
	while(TRUE)
	{  
		if(va==67)
		{
			StepmotorLeft();
		}
		else if(va==64){
			StepmotorRight();
		}
		else{
			stepmotinit();
		}		
		DigDisplay(va);
	}
} 
