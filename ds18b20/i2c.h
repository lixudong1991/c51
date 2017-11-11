#ifndef I2C_H
#define I2C_H

#include "common.h"

#define SCL P2^1
#define SDA P2^0

uint8 writei2c(uint8 addr,uint8 dat);
uint8 readi2c(uint8 addr);

#endif