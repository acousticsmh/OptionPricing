#include "AntiThetic.h"

AntiThetic::AntiThetic(const Wrapper<RandomBase> &
                           innerGenerator)
    : RandomBase(*innerGenerator),
      InnerGenerator(innerGenerator)
{
    InnerGenerator->Reset();
    OddEven = true;
    NextVariates.resize(GetDimension());
}

RandomBase *AntiThetic::clone() const
{
    return new AntiThetic(*this);
}

void AntiThetic::GetUniforms(MJArray &variates)
{
    InnerGenerator->GetUniforms(variates);
    int i = 0;
    if (OddEven)
    {
        while (i < GetDimension())
        {
            NextVariates[i] = 1 - variates[i];
            i++;
        }
        OddEven = false;
    }
    else
    {
        variates = NextVariates;
        OddEven = true;
    }
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
    if (numberOfPaths == 0)
        return;
    if (OddEven)
    {
        OddEven = false;
        numberOfPaths--;
    }
    InnerGenerator->Skip(numberOfPaths / 2);
    if (numberOfPaths % 2)
    {
        MJArray tmp(GetDimension());
        GetUniforms(tmp);
    }
}

void AntiThetic::SetSeed(unsigned long Seed)
{
    InnerGenerator->SetSeed(Seed);
    OddEven = true;
}

void AntiThetic::ResetDimensionality(unsigned long
                                         NewDimension)
{
    RandomBase::ResetDimension(NewDimension);
    InnerGenerator->ResetDimension(NewDimension);
    NextVariates.resize(NewDimension);
}

void AntiThetic::Reset()
{
    InnerGenerator->Reset();
    OddEven = true;
}