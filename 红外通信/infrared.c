#include "infrared.h"
sbit ird=IRD;

uint8 getinfrdata(uint8 *val)
{
	uint8 ret=0,i=0,j=0;
	uint16 err=2000;
	uint8 dat[4]={0,0,0,0};
	while(err--);
	if(!ird)
	{
		err=9000;
		while(!ird&&err--);
		if(ird)
		{
			err=5500;
			while(ird&&err--);
			if(!ird)
			{
				for(j=0;j<4;j++)
				{
					for(i=0;i<8;i++){
						err=6500;
						while(!ird&&err--);
						if(ird)
						{
							err=3000;
							while(ird&&err--);
							if(err)
							{
								dat[j]>>=1;
								if(err<2200)
								{
									dat[j]|=0x80;	
								}
							}
						}
					}
				}
				if(dat[2]&&(dat[2]==~dat[3]))
				{
					ret=1;
					*val=dat[2];
				}
			}
		}
	}
	return ret;	
}