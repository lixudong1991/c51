#ifndef MY_COM
#define MY_COM

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef uint8
#define uint8 unsigned char
#endif

#ifndef uint16
#define uint16 unsigned int
#endif

#ifndef uint32
#define uint32 unsigned long
#endif
char code number[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xff};
void waitms(uint32 v)	  //
{	
	uint16 i=0;
	for(;i<100;i++)
	{	
		uint16 j=0;
		for(;j<v;j++);
	}
}

void waitus(uint32 v)	  //ºÁÃë
{	
	while(v--);
}

#endif