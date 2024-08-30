#include <iostream>
#include <cmath>
#include <string>
#include "Random/Random2.h"
#include "Random/AntiThetic.h"
#include "Random/ParkMiller.h"
#include "PayOff/PayOffBridge.h"
#include "Wrappers/Wrapper.h"
#include "Statistics/ConvergenceTable.h"
#include "utils/utils.h"
#include "Parameters/Parameters.h"
#include "Statistics/Statistics.h"
#include "Option/ExoticBSEngine.h"
#include "Option/PathDependantAsian.h"

using namespace std;

int main()
{
    double S_0;
    double K = 110;
    double T;
    double r;
    double d;
    double sigma;
    int N;

    unsigned long numDates;

    T = 2.0;

    S_0 = 100.0;

    r = 0.03;

    d = 0.0;

    sigma = 0.15;

    N = 1000000;

    K = 110.0;

    numDates = 20;

    PayOffCall thePayOff(K);

    MJArray times(numDates);

    for (unsigned long i = 0; i < numDates; i++)
        times[i] = (i + 1.0) * T / numDates;

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    ParametersConstant VolParam(sigma);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    RandomParkMiller generator(numDates);
    AntiThetic GenTwo(generator);

    PathDependentAsian theOption(times, T, thePayOff);
    ExoticBSEngine theEngine(theOption, rParam, dParam,
                             VolParam, GenTwo, S_0);
    theEngine.DoSimulation(gathererTwo, N);
    vector<vector<double>> results =
        gathererTwo.GetResultsSoFar();
    cout << "\nFor the Option price the results are \n";
    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

// cout << "\nEnter expiry\n";
//     cin >> T;

//     cout << "\n Enter Current Stock Price\n";
//     cin >> S_0;

//     cout << "\n Enter Risk Free Interest Rate\n";
//     cin >> r;

//     cout << "\n Enter Dividend Rate \n";
//     cin >> d;

//     cout << "\n Enter Volatility\n";
//     cin >> sigma;

//     cout << "\n Enter Number of Simulated Paths\n";
//     cin >> N;

//     cout << "\n Enter Strike Price\n";
//     cin >> K;

//     cout << "\n Enter Number of Dates\n";
//     cin >> numDates;