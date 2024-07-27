#ifndef RANDOM2_H
#define RANDOM2_H

#include "Arrays.h"

class RandomBase
{
public:
    RandomBase(unsigned long Dimensions_);
    inline unsigned long GetDimension() const;
    virtual RandomBase *clone() const = 0;
    virtual void GetUniforms(MJArray &variates) = 0;
    virtual void GetGaussians(MJArray &variates);
    virtual void SetSeed(unsigned long Seed_) = 0;
    virtual void Skip(unsigned long numberOfPaths) = 0;
    virtual void Reset() = 0;
    virtual void ResetDimension(unsigned long
                                    NewDimensionality);
    virtual ~RandomBase() = default;

private:
    unsigned long Dimension;
};

unsigned long RandomBase::GetDimension() const
{
    return Dimension;
}
#endif