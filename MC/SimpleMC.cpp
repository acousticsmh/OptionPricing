#include "SimpleMC.h"
#include "../Random/Random1.h"
#include <cmath>

double SimpleMonteCarlo2(const PayOff &thePayOff,
                         double T,
                         double S_0,
                         double sigma,
                         double r,
                         double N)
{
    double sum_payoffs = 0.0;
    int i = 0;
    double drifted_stock = S_0 * exp((r - sigma * sigma / 2) * T);
    double std_deviation = sigma * sqrt(T);
    while (i < N)
    {
        double normal = GetOneGaussianByBoxMuller();
        double stock_price = drifted_stock * exp(normal * std_deviation);
        double payoff = thePayOff(stock_price);
        sum_payoffs += payoff;
        i++;
    }
    double simulated_price = exp(-r * T) * (sum_payoffs / (1.0 * N));
    return simulated_price;
}