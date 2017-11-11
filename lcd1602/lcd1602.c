
#include"lcd1602.h"

void lcd_delay(uint16 c)
{
  uint8 a,b;
  for(;c>0;c--)
  {
	  for(b=199;b>0;b--)
	  {
	   	for(a=1;a>0;a--);
	  }
  }
}
void lcd_write(uint8 mode,uint8 dat)
{
	LCD1602_E=0;
	LCD1602_RS=mode;
	LCD1602_RW=0;
	LCD1602_DATA = dat;
	lcd_delay(1);
	LCD1602_E=1;
	lcd_delay(5);
    LCD1602_E=0;
}
void lcd_init()
{
	lcd_write(COM,LCDMOD);
	lcd_write(COM,LCDOC);
	lcd_write(COM,LCDSET);
	lcd_write(COM,LCDCLR);
    lcd_write(COM,INITPOS);
}
void lcd_print(const uint8* mess)
{   
   uint8 *p=mess;
   uint8 i=0; 
   while(*p!='\0'&&i<32)
   {
    	if(i==16)
		{
		  lcd_write(COM,0xc0);
		}
		lcd_write(DAT,*p);
		p++;
		i++;
   }
}