#ifndef MY_COM
#define MY_COM

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef uint16
#define uint16 unsigned int
#endif

#ifndef uint8
#define uint8 unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long
#endif

void waitms(uint32 v)	  //
{	
	uint16 i=0;
	for(;i<100;i++)
	{	
		uint16 j=0;
		for(;j<v;j++);
	}
} 

void waitus(uint32 v)	  //����
{	
	while(v--);
} 
#endif