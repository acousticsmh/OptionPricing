#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_)
{
    Seed = Seed_;
    if (Seed == 0)
        Seed = 1;
}

unsigned long ParkMiller::Max()
{
    return m - 1;
}

unsigned long ParkMiller::Min()
{
    return 1;
}

void ParkMiller::SetSeed(long Seed_)
{
    Seed = Seed_;
    if (Seed == 0)
        Seed = 1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k;
    k = Seed / q;
    Seed = a * (Seed - k * q) - r * k;
    if (Seed < 0)
        Seed += m;
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimension_, unsigned long Seed_) : RandomBase(Dimension_),
                                                                                    InnerGenerator(Seed_),
                                                                                    InitialSeed(Seed_)
{
    Reciprocal = 1 / (1.0 + InnerGenerator.Max());
}

RandomBase *RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray &variates)
{
    for (unsigned long j = 0; j < GetDimension(); j++)
        variates[j] =
            InnerGenerator.GetOneRandomInteger() * Reciprocal;
}
void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimension());
    for (unsigned long j = 0; j < numberOfPaths; j++)
        GetUniforms(tmp);
}
void RandomParkMiller::SetSeed(unsigned long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}
void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long
                                               NewDimension)
{
    RandomBase::ResetDimension(NewDimension);
    InnerGenerator.SetSeed(InitialSeed);
}