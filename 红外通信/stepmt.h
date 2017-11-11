#ifndef STEPMT_H
#define STEPMT_H

#include "common.h"

#define MOTOA P1^0
#define MOTOB P1^1
#define MOTOC P1^2
#define MOTOD P1^3

#define TIM 400

void StepmotorLeft();
void StepmotorRight();
void stepmotinit();	
#endif