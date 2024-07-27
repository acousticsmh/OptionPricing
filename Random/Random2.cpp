#include "Random2.h"
#include "Normals.h"
#include <cstdlib>

void RandomBase::GetGaussians(MJArray &variates)
{
    GetUniforms(variates);
    for (unsigned long i = 0; i < Dimension; i++)
    {
        double x = variates[i];
        variates[i] = InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimension(unsigned long
                                    NewDimension)
{
    Dimension = NewDimension;
}
RandomBase::RandomBase(unsigned long Dimension_)
{
    Dimension = Dimension_;
}