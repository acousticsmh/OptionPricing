#include "PathDependent.h"

PathDependent::PathDependent(const MJArray &LookAtTimes_)
{
    LookAtTimes = LookAtTimes_;
}

MJArray PathDependent::GetLookAtTimes() const
{
    return LookAtTimes;
}

unsigned long PathDependent::MaxNumberOfCashFlows() const
{
    return LookAtTimes.size();
}