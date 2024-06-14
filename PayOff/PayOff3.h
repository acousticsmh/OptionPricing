#ifndef PAYOFF3_H
#define PAYOFF3_H
#include "PayOff2.h"

class PayOffDigital : public PayOff
{
public:
    PayOffDigital(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDigital() {}

private:
    double Strike;
};

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double lowerStrike_, double upperStrike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital() {}

private:
    double lowerStrike;
    double upperStrike;
};

#endif