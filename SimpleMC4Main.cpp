#include <iostream>
#include <cmath>
#include <string>
#include "Random/Random1.h"
#include "MC/SimpleMC4.h"
#include "PayOff/PayOffBridge.h"
#include "Option/Vanilla2.h"
#include "utils/utils.h"
#include "Parameters/Parameters.h"

using namespace std;

int main()
{
    double S_0;
    double K = 110;
    double T;
    double r;
    double sigma;
    int N;
    int optionType;

    PayOff *thePayOff;

    cout << "\nEnter expiry\n";
    cin >> T;

    cout << "\n Enter Current Stock Price\n";
    cin >> S_0;

    cout << "\n Enter Risk Free Interest Rate\n";
    cin >> r;

    cout << "\n Enter Volatility\n";
    cin >> sigma;

    cout << "\n Enter Number of Simulated Paths\n";
    cin >> N;

    cout << "\n Enter 0 for Call Option, 1 for Put Option\n";
    cin >> optionType;

    cout << "\n Enter Strike Price\n";
    cin >> K;

    if (optionType == 0)
        thePayOff = new PayOffCall(K);
    else
        thePayOff = new PayOffPut(K);

    VanillaOption theOption(PayOffBridge(*thePayOff), T);

    ParametersConstant VolParam(sigma);
    ParametersConstant rParam(r);
    double option_price = SimpleMonteCarlo3(theOption,
                                            S_0,
                                            VolParam,
                                            rParam,
                                            N);

    double call_price = black_scholes_price(S_0, sigma, r, T, K);
    double put_price = get_put_from_call(S_0, call_price, K, r, T);
    cout << "Monte Carlo Option Price " << option_price << endl;
    cout << "Black Scholes Call Option Price " << call_price << endl;
    cout << "Black Scholes Put Option Price " << put_price << endl;

    return 0;
}