#include "TreeAmerican.h"

TreeAmerican::TreeAmerican(double FinalTime_,
                           const PayOffBridge &ThePayOff_)
    : TreeProduct(FinalTime_), ThePayOff(ThePayOff_)
{
}

TreeProduct *TreeAmerican::clone() const
{
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, double DiscountValue) const
{
    double payOff = ThePayOff(Spot);
    if (payOff > DiscountValue)
        return payOff;
    return DiscountValue;
}
