#ifndef SIMPLEMC4_H
#define SIMPLEMC4_H
#include "../Option/Vanilla2.h"
#include "../Parameters/Parameters.h"
double SimpleMonteCarlo4(const VanillaOption &TheOption,
                         double S_0,
                         const Parameters &Vol,
                         const Parameters &r,
                         unsigned long N);
#endif