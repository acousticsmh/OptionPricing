#ifndef SIMPLEMC_2_H
#define SIMPLEMC_2_H
#include "../PayOff/PayOff2.h"
double SimpleMonteCarlo2(const PayOff &thePayOff,
                         double T,
                         double S_0,
                         double sigma,
                         double r,
                         double N);
#endif