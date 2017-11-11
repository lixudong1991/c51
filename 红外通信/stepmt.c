#include "stepmt.h"
sbit motoa=MOTOA;
sbit motob=MOTOB;
sbit motoc=MOTOC;
sbit motod=MOTOD;
void stepmotinit()
{
	motoa=0;
	motob=0;
	motoc=0;
	motod=0;
}
void StepmotorLeft()
{
		 motoa=0;
		 motob=1;
		 motoc=1;
		 motod=1;
		 waitus(TIM);
		 motoa=1;
		 motob=0;
		 motoc=1;
		 motod=1;
		 waitus(TIM);
		 motoa=1;
		 motob=1;
		 motoc=0;
		 motod=1;
		 waitus(TIM);
		 motoa=1;
		 motob=1;
		 motoc=1;
		 motod=0;
		 waitus(TIM);	
}
void StepmotorRight()
{
		 motoa=1;
		 motob=0;
		 motoc=1;
		 motod=1;
		 waitus(TIM);
		 motoa=0;
		 motob=1;
		 motoc=1;
		 motod=1;
		 waitus(TIM);
		 motoa=1;
		 motob=1;
		 motoc=1;
		 motod=0;
		 waitus(TIM);
		 motoa=1;
		 motob=1;
		 motoc=0;
		 motod=1;
		 waitus(TIM);	
}