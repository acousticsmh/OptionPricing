#include "ExoticEngine.h"
#include <cmath>
#include <iostream>
ExoticEngine::ExoticEngine(const Wrapper<PathDependent> &
                               TheProduct_,
                           const Parameters &r_)
    : TheProduct(TheProduct_),
      r(r_),
      Discounts(TheProduct_->PossibleCashFlowTimes())
{
    for (unsigned long i = 0; i < Discounts.size(); i++)
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC &TheGatherer, unsigned long NumberOfPaths)
{

    MJArray SpotValues(TheProduct->GetLookAtTimes().size());
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
    double thisValue;
    for (unsigned long i = 0; i < NumberOfPaths; ++i)
    {
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }
    return;
}

double ExoticEngine::DoOnePath(const MJArray &SpotValues) const
{
    double Value = 0.0;
    unsigned long NumCashFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
    // std::cout << "Recieved Cash Flows" << std::endl;
    unsigned long i = 0;
    while (i < NumCashFlows)
    {
        Value += TheseCashFlows[i].Amount * Discounts[TheseCashFlows[i].TimeIndex];
        i++;
    }
    return Value;
}