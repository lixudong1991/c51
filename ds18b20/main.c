#include "ds18b20.h"
#include "dig.h"
int main()
{
	while(TRUE)
	{  
		DigDisplay(readTemperature());				   	
	}
} 
