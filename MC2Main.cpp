#include <iostream>
#include <cmath>
#include <string>
#include "Random/Random1.h"
#include "MC/SimpleMC.h"
#include "PayOff/PayOff1.h"

using namespace std;

double phi(double x)
{
    // Function to find CDF of x in Standard Normal Distribution
    // Check Details Here : https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
    double a1 = 0.254829592;
    double a2 = -0.284496736;
    double a3 = 1.421413741;
    double a4 = -1.453152027;
    double a5 = 1.061405429;
    double p = 0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x) / sqrt(2.0);

    double t = 1.0 / (1.0 + p * x);
    double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x);

    return 0.5 * (1.0 + sign * y);
}

double black_scholes_price(double S_0, double sigma, double r, double T, double K)
{
    double d1 = (log(S_0 / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double d2 = (log(S_0 / K) + (r - sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double price = S_0 * phi(d1) - K * exp(-r * T) * phi(d2);
    return price;
}

int main()
{
    double S_0 = 100;
    double K = 110;
    double T = 2.0;
    double r = 0.03;
    double sigma = 0.15;
    int N = 10000000;

    PayOff callPayOff(K, PayOff::call);
    PayOff putPayOff(K, PayOff::put);

    double call_price = SimpleMonteCarlo2(callPayOff, T, S_0, sigma, r, N);
    double put_price = SimpleMonteCarlo2(putPayOff, T, S_0, sigma, r, N);
    double actual_price = black_scholes_price(S_0, sigma, r, T, K);
    cout << "Monte Carlo Call Option Price " << call_price << endl;
    cout << "Monte Carlo Put Option Price " << put_price << endl;
    cout << "Black Scholes Call Option Price " << actual_price << endl;

    return 0;
}