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

StatisticsVaR::StatisticsVaR(double confidenceLevel_)
{
    confidenceLevel = confidenceLevel_;
}

vector<vector<double>> StatisticsVaR::GetResultsSoFar() const
{
    vector<vector<double>> results(1);
    results[0].resize(1);
    std::vector<double> sortedResults = Results;
    std::sort(sortedResults.begin(), sortedResults.end());
    int numObservations = Results.size();
    int index = std::ceil((1 - confidenceLevel) * numObservations);

    results[0][0] = sortedResults[index];
    return results;
}

void StatisticsVaR::DumpOneResult(double result)
{
    Results.push_back(result);
}

StatisticsMC *StatisticsVaR::clone() const
{
    return new StatisticsVaR(*this);
}