#include"dig.h"
#include"key16.h"
#include"i2c.h"
int main()
{
	uint8 c=0;
    uint8 m=0;  
	while(TRUE)
	{  
		if(keydown(&c))
		{
			switch(c)
			{
				case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
					m=m*10+c;
					break;
				case 10:
					writei2c(0,m);
					break;	
				case 11:
					m=readi2c(0);
					break;
				case 12:
					m++;
					break;
				case 13:
					m--;
					break;
				case 14:
					m=0;
					break;
				default:
					break;
			}
		}
		DigDisplay(m);				   	
	}
} 
