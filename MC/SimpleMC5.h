#ifndef SIMPLEMC5_H
#define SIMPLEMC5_H
#include "../Option/Vanilla2.h"
#include "../Parameters/Parameters.h"
#include "../Statistics/Statistics.h"
void SimpleMonteCarlo5(const VanillaOption &TheOption,
                       double S_0,
                       const Parameters &Vol,
                       const Parameters &r,
                       unsigned long N,
                       StatisticsMC &gatherer);
#endif