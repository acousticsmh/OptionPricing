#include <iostream>
#include <cmath>
#include <string>
#include "Random/Random1.h"
#include "MC/SimpleMC2.h"
#include "PayOff/PayOff2.h"

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
    double S_0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
    int optionType;

    PayOff *thisPayOff;

    cout << "\nEnter expiry\n";
    cin >> T;

    cout << "\n Enter Current Stock Price\n";
    cin >> S_0;

    cout << "\n Enter Strike Price\n";
    cin >> K;

    cout << "\n Enter Risk Free Interest Rate\n";
    cin >> r;

    cout << "\n Enter Volatility\n";
    cin >> sigma;

    cout << "\n Enter Number of Simulated Paths\n";
    cin >> N;

    cout << "\n Enter 0 for Call Option, else Put Option\n";
    cin >> optionType;

    if (optionType == 0)
        thisPayOff = new PayOffCall(K);
    else
        thisPayOff = new PayOffPut(K);

    double option_price = SimpleMonteCarlo2(*thisPayOff, T, S_0, sigma, r, N);
    double actual_price = black_scholes_price(S_0, sigma, r, T, K);
    cout << "Monte Carlo Option Price " << option_price << endl;
    cout << "Black Scholes Call Option Price " << actual_price << endl;

    delete thisPayOff;

    return 0;
}