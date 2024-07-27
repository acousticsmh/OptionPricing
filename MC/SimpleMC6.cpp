#include "SimpleMC5.h"
#include "../Random/Random2.h"
#include "../Random/Arrays.h"
#include <cmath>

using namespace std;
void SimpleMonteCarlo6(const VanillaOption &TheOption,
                       double S_0,
                       const Parameters &Vol,
                       const Parameters &r,
                       unsigned long N,
                       StatisticsMC &gatherer,
                       RandomBase &generator)
{
    double sum_payoffs = 0.0;
    double T = TheOption.GetExpiry();
    int i = 0;
    double sigma = sqrt(Vol.IntegralSquare(0, T));
    double discount = exp(-r.Integral(0, T));
    double drifted_stock = S_0 * exp((r.Integral(0, T) - sigma * sigma / 2));
    MJArray variates(1);
    while (i < N)
    {
        generator.GetGaussians(variates);
        double stock_price = drifted_stock * exp(variates[0] * sigma);
        double payoff = TheOption.OptionPayOff(stock_price);
        gatherer.DumpOneResult(payoff * discount);
        i++;
    }
    return;
}