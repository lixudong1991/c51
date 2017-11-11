#ifndef DIG_H
#define DIG_H

#include<stc12c.h>
#include"main.h"


#define LED P0
#define LEDBIT P2

 
sbit DIG_A=LEDBIT^2;
sbit DIG_B=LEDBIT^3;
sbit DIG_C=LEDBIT^4;

void waitus(uint32 v);	  //∫¡√Î
void DigDisplay(uint32 v);

#endif