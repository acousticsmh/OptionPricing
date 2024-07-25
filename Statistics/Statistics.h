#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC() {}
    virtual void DumpOneResult(double result) = 0;

    virtual std::vector<std::vector<double>> GetResultsSoFar() const = 0;

    virtual StatisticsMC *clone() const = 0;

    virtual ~StatisticsMC() {}
};

class StatisticsMean : public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual StatisticsMC *clone() const;

private:
    double RunningSum;
    unsigned long PathsDone;
};

class StatisticsVaR : public StatisticsMC
{
public:
    StatisticsVaR(double confidenceLevel_ = 0.05);
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual StatisticsMC *clone() const;

private:
    std::vector<double> Results;
    double confidenceLevel;
};

#endif