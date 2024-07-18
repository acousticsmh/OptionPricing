#include "Statistics.h"
using namespace std;
StatisticsMean::StatisticsMean()
{
    RunningSum = 0.0;
    PathsDone = 0;
}

void StatisticsMean::DumpOneResult(double result)
{
    RunningSum += result;
    PathsDone++;
}

vector<vector<double>> StatisticsMean::GetResultsSoFar() const
{
    vector<vector<double>> results(1);
    results[0].resize(1);
    results[0][0] = RunningSum / PathsDone;
    return results;
}

StatisticsMC *StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}