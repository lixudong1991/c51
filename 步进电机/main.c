#include<stc12c.h>
#include<reg52.h>
#include"main.h"
#define TIM 400

sbit MOTOA=P1^0;
sbit MOTOB=P1^1;
sbit MOTOC=P1^2;
sbit MOTOD=P1^3;

int main()
{
	P1=0;
	while(TRUE)
	{	  
		 MOTOA=0;
		 MOTOB=1;
		 MOTOC=1;
		 MOTOD=1;
		 waitus(TIM);
		 MOTOA=1;
		 MOTOB=0;
		 MOTOC=1;
		 MOTOD=1;
		 waitus(TIM);
		 MOTOA=1;
		 MOTOB=1;
		 MOTOC=0;
		 MOTOD=1;
		 waitus(TIM);
		 MOTOA=1;
		 MOTOB=1;
		 MOTOC=1;
		 MOTOD=0;
		 waitus(TIM);	
	}	 
}