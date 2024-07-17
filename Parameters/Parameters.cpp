#include "Parameters.h"
Parameters::Parameters(const ParametersInner &innerObject)
{
    InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters &original)
{
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters &Parameters::operator=(const Parameters &original)
{
    if (this != &original)
    {
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}

Parameters::~Parameters()
{
    delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const
{
    double total = Integral(time1, time2);
    return total / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1,
                                  double time2) const
{
    double total = IntegralSquare(time1, time2);
    return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double constant)
{
    Constant = constant;
    ConstantSquare = Constant * Constant;
}

ParametersInner *ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1,
                                    double time2) const
{
    return (time2 - time1) * Constant;
}

double ParametersConstant::IntegralSquare(double time1,
                                          double time2) const
{
    return (time2 - time1) * ConstantSquare;
}

ParametersPiecewiseConstant::ParametersPiecewiseConstant(double Constant1, double Constant2, double time1)
{
    constant1 = Constant1;
    constant2 = Constant2;
    changeTime = time1;
}

ParametersInner *ParametersPiecewiseConstant::clone() const
{
    return new ParametersPiecewiseConstant(*this);
}

double ParametersPiecewiseConstant::Integral(double time1,
                                             double time2) const
{
    if (time2 < changeTime)
        return constant1 * (time2 - time1);
    if (time1 > changeTime)
        return constant2 * (time2 - time1);
    return constant1 * (changeTime - time1) + constant2 * (time2 - changeTime);
}

double ParametersPiecewiseConstant::IntegralSquare(double time1,
                                                   double time2) const
{
    if (time2 < changeTime)
        return constant1 * constant1 * (time2 - time1);
    if (time1 > changeTime)
        return constant2 * constant2 * (time2 - time1);
    return constant1 * constant1 * (changeTime - time1) + constant2 * constant2 * (time2 - changeTime);
}