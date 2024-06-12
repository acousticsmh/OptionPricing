#include "PayOff3.h"
PayOffDigital::PayOffDigital(double Strike_)
{
    Strike = Strike_;
}

PayOffDoubleDigital::PayOffDoubleDigital(double lowerStrike_, double upperStrike_)
{
    lowerStrike = lowerStrike_;
    upperStrike = upperStrike_;
}

double PayOffDigital::operator()(double Spot) const
{
    if (Spot > Strike)
        return 1;
    return 0;
}

double PayOffDoubleDigital::operator()(double Spot) const
{
    if (Spot < upperStrike && Spot > lowerStrike)
        return 1;
    return 0;
}