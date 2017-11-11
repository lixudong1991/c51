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

#ifndef uint32
#define uint32 unsigned long
#endif

/*∂‘”¶º¸≈Ã
	1 2 3 +
	4 5 6 -
	7 8 9 *
	0 .	= /
*/
char keys[4][4]={
					{0xf9,0xa4,0xb0,'+'},
					{0x99,0x92,0x82,'-'},
					{0xf8,0x80,0x90,'*'},
					{0xc0,'=', '.', '/'},
				};
void waitms(uint16 v)	  //
{	
	uint16 i=0;
	for(;i<100;i++)
	{	
		uint16 j=0;
		for(;j<v;j++);
	}
}

void waitus(uint16 v)	  //∫¡√Î
{	
	while(v--);
}
sbit p22=P2^2;
sbit p23=P2^3;
sbit p24=P2^4;

void DigDisplay(uint32 v)
{
	uint32 sum = 0;
	uint32 m = 10;
	char j=7;
	if(v<10)
	{
	 	p22=1;
		p23=1;
		p24=1;
		P1=~number[v];
		return;	
	}
	while (sum!=v)
	{
		char n=(v%m-sum)/(m/10);
	   	p22=j&1;
		p23=(j&2)>>1;
		p24=(j&4)>>2;	
		P1=~number[n];
		waitus(50);
		P1=0;
		sum = v%m;
		m = m*10; 
		j--;		
	}
	
}

sbit beep=P2^7;
void beepfun()
{
	beep=1;
	waitus(3);
	beep=0;
	waitus(25);
}

char getv(char v)
{
	switch(v)
	{
		case 7:
			return 3;
		case 11:
		 	return 2;
		case 13:
			return 1;
		case 14:
		 	return 0;
	}
	return 0;
}


void keydown(char* ch)
{
	char n=0;
	P0=0xf0;
	if(P0!=0xf0)
	{
	    waitus(1000);
		if(P0!=0xf0)
		{
		   char x=getv(P0>>4);
		   P0=0x0f;
		   if(P0!=0x0f)
		   {
		      char y=getv(P0);
			  *ch =key[y][x];	
		   }		   
		   while(n++<250&&P0!=0x0f)
		   {
			  beepfun();	 
		   }	   		                     
		}
		
	}
}

#endif