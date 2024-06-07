#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "../PayOff/PayOff1.h"
double SimpleMonteCarlo2(const PayOff &thePayOff,
                         double T,
                         double S_0,
                         double sigma,
                         double r,
                         double N);
#endif