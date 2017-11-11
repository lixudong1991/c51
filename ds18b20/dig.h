#ifndef DIG_H
#define DIG_H

#include "common.h"


#define LED P0
#define DIG_A P2^2
#define DIG_B P2^3
#define DIG_C P2^4

	 
void DigDisplay(uint32 v);
#endif