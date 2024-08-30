#include "ExoticBSEngine.h"
#include <cmath>
#include <iostream>

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent> &TheProduct_,
                               const Parameters &R_,
                               const Parameters &D_,
                               const Parameters &Vol_,
                               const Wrapper<RandomBase> &TheGenerator_,
                               double Spot_) : ExoticEngine(TheProduct_, R_),
                                               TheGenerator(TheGenerator_)
{

    MJArray Times(TheProduct_->GetLookAtTimes());
    NumberOfTimes = Times.size();
    TheGenerator->ResetDimension(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);
    double Variance = Vol_.IntegralSquare(0, Times[0]);
    Drifts[0] = R_.Integral(0.0, Times[0]) - D_.Integral(0.0, Times[0]) - 0.5 * Variance;
    StandardDeviations[0] = sqrt(Variance);
    unsigned long j = 0;
    while (j < NumberOfTimes)
    {
        double thisVariance = Vol_.IntegralSquare(Times[j - 1], Times[j]);
        Drifts[j] = R_.Integral(Times[j - 1], Times[j]) - D_.Integral(Times[j - 1], Times[j]) - 0.5 * thisVariance;
        StandardDeviations[j] = sqrt(thisVariance);
        j++;
    }
    LogSpot = log(Spot_);
    Variates.resize(NumberOfTimes);
}

void ExoticBSEngine::GetOnePath(MJArray &SpotValues)
{
    double currLogSpot = LogSpot;
    unsigned long i = 0;
    TheGenerator->GetGaussians(Variates);
    // std::cout << "Recieved Normal Numbers" << std::endl;
    while (i < NumberOfTimes)
    {
        currLogSpot += Drifts[i] + Variates[i] * StandardDeviations[i];
        SpotValues[i] = exp(currLogSpot);
        // std::cout << "Spot Value is " << SpotValues[i] << std::endl;
        // std::cout << "Std Deviation is " << StandardDeviations[i] << std::endl;
        // std::cout << "Variates Value is " << Variates[i] << std::endl;
        i++;
    }
    return;
}