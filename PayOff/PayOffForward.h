#ifndef PAYOFFFORWARD_H
#define PAYOFFFORWARD_H
#include "PayOff4.h"

class PayOffForward : public PayOff
{
public:
    PayOffForward(double Strike_);
    virtual double operator()(double Spot) const;
    virtual PayOff *clone() const;
    virtual ~PayOffForward() {}

private:
    double Strike;
};
#endif