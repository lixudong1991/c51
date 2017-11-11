#include<stc12c.h>
#include"lcd1602.h"


int main()
{
   lcd_init();
   lcd_print("I LOVE YUO! 123 abcde:");
   while(TRUE);
} 