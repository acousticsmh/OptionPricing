#include <iostream>
#include <cmath>
#include <string>
#include "Random/Random1.h"

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

double monte_carlo_option_price(double S_0, double sigma, double r, double T, double K, int N)
{
    // default_random_engine generator;
    // normal_distribution<double> distribution(0.0, 1.0);
    double sum_payoffs = 0.0;
    int i = 0;
    double drifted_stock = S_0 * exp((r - sigma * sigma / 2) * T);
    double std_deviation = sigma * sqrt(T);
    while (i < N)
    {
        // double normal = distribution(generator);
        double normal = GetOneGaussianByBoxMuller();
        double stock_price = drifted_stock * exp(normal * std_deviation);
        double payoff = max(stock_price - K, 0.0);
        sum_payoffs += payoff;
        i++;
    }
    double simulated_price = exp(-r * T) * (sum_payoffs / (1.0 * N));
    return simulated_price;
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
    int N = 100000000;
    int i = 0;
    double simulated_price = monte_carlo_option_price(S_0, sigma, r, T, K, N);
    double actual_price = black_scholes_price(S_0, sigma, r, T, K);
    cout << "Hi There, How are you? " << endl;
    cout << "Monte Carlo Price " << simulated_price << endl;
    cout << "Black Scholes Option Price " << actual_price << endl;

    return 0;
}