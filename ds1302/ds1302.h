#ifndef DS1302_H
#define DS1302_H

#include "common.h"

#define SCLK P3^6
#define DSCE P3^5
#define DSIO P3^4

void write1302time(uint32 time);
uint32 read1302time();
#endif