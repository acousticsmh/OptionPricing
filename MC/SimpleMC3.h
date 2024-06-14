#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H
#include "../Option/Vanilla.h"
double SimpleMonteCarlo3(const VanillaOption &TheOption,
                         double S_0,
                         double sigma,
                         double r,
                         unsigned long N);
#endif