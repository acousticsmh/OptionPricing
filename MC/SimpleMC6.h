#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H
#include "../Option/Vanilla2.h"
#include "../Parameters/Parameters.h"
#include "../Random/Random2.h"
#include "../Statistics/Statistics.h"
void SimpleMonteCarlo6(const VanillaOption &TheOption,
                       double Spot,
                       const Parameters &Vol,
                       const Parameters &r,
                       unsigned long NumberOfPaths,
                       StatisticsMC &gatherer,
                       RandomBase &generator);
#endif