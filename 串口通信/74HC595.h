#ifndef _74HC595_H
#define _74HC595_H

#include<stc12c.h>

#include<intrins.h>
#include"main.h"

sbit SER=P3^4;
sbit RCK=P3^5;
sbit SCK=P3^6;

void write595(uint8 v,uint8 v1);

#endif