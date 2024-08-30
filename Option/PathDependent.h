#ifndef PATHDEPENDENT_H
#define PATHDEPENDENT_H
#include "../Random/Arrays.h"
#include <vector>

class CashFlow
{
public:
    CashFlow(unsigned long TimeIndex_ = 0UL, double Amount_ = 0.0)
        : TimeIndex(TimeIndex_),
          Amount(Amount_) {};

    double Amount;
    unsigned long TimeIndex;
};

class PathDependent
{
public:
    PathDependent(const MJArray &LookAtTimes_);
    virtual MJArray GetLookAtTimes() const;
    virtual unsigned long MaxNumberOfCashFlows() const = 0;
    virtual MJArray PossibleCashFlowTimes() const = 0;
    virtual unsigned long CashFlows(const MJArray &SpotValues, std::vector<CashFlow> &GeneratedFlows) const = 0;
    virtual PathDependent *clone() const = 0;
    virtual ~PathDependent() {}

private:
    MJArray LookAtTimes;
};

#endif