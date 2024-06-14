#include "PayOff4.h"
#include <algorithm>

PayOffCall::PayOffCall(double Strike_)
{
    Strike = Strike_;
}

PayOffPut::PayOffPut(double Strike_)
{
    Strike = Strike_;
}

PayOff *PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

PayOff *PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike, 0.0);
}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot, 0.0);
}