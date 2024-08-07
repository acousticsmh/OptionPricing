#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H
#include "Statistics.h"
#include "../Wrappers/Wrapper.h"
class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(const Wrapper<StatisticsMC> &Inner_);
    virtual StatisticsMC *clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;

private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};
#endif