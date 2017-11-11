#include "dig.h"
#include "ds1302.h"
int main()
{
//	write1302time(360);
	while(TRUE)
	{  
		DigDisplay(read1302time());
	}
} 
