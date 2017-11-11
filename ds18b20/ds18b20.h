#ifndef DS18B20_H
#define DS18B20_H

#include "common.h"

#ifndef DS18IO
#define DS18IO P3^7
#endif

uint16 readTemperature();

#endif