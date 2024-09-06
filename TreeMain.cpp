#include "Option/BinomialTree.h"
#include "Option/TreeAmerican.h"
#include "Option/TreeEuropean.h"
#include "PayOff/PayOffForward.h"
#include "PayOff/PayOffBridge.h"
#include "PayOff/PayOff4.h"
#include "utils/utils.h"
#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    double S_0;
    double K;
    double T;
    double r;
    double d;
    double sigma;

    unsigned long numSteps;

    cout << "\nEnter expiry\n";
    cin >> T;

    cout << "\n Enter Current Stock Price\n";
    cin >> S_0;

    cout << "\n Enter Risk Free Interest Rate\n";
    cin >> r;

    cout << "\n Enter Dividend Rate \n";
    cin >> d;

    cout << "\n Enter Volatility\n";
    cin >> sigma;

    cout << "\n Enter Strike Price\n";
    cin >> K;

    cout << "\n Enter Number of Steps\n";
    cin >> numSteps;

    PayOffCall thePayOff(K);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    TreeEuropean europeanOption(T, thePayOff);
    TreeAmerican americanOption(T, thePayOff);
    SimpleBinomialTree theTree(S_0, rParam, dParam, sigma, numSteps,
                               T);
    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    cout << "euro price " << euroPrice << "\namer price " << americanPrice << "\n";
    double BSPrice = black_scholes_price(S_0, sigma, r, T, K);
    cout << "BS formula euro price    " << BSPrice << "\n";
    PayOffForward forwardPayOff(K);
    TreeEuropean forward(T, forwardPayOff);
    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree     " << forwardPrice << "\n";
    double actualForwardPrice =
        exp(-r * T) * (S_0 * exp((r - d) * T) - K);
    cout << "forward price      " << actualForwardPrice << "\n";
    numSteps++;
    SimpleBinomialTree theNewTree(S_0, rParam, dParam, sigma,
                                  numSteps, T);
    double euroNewPrice =
        theNewTree.GetThePrice(europeanOption);
    double americanNewPrice =
        theNewTree.GetThePrice(americanOption);
    cout << "euro new price     " << euroNewPrice
         << "\namer new price        " << americanNewPrice << "\n";
    double forwardNewPrice = theNewTree.GetThePrice(forward);
    cout << "forward price by new tree      " << forwardNewPrice
         << "\n";
    double averageEuro = 0.5 * (euroPrice + euroNewPrice);
    double averageAmer = 0.5 * (americanPrice + americanNewPrice);
    double averageForward = 0.5 * (forwardPrice + forwardNewPrice);
    cout << "euro av price      " << averageEuro << "\namer av price     "
         << averageAmer << "\n";
    cout << "av forward     " << averageForward << "\n";
    return 0;
}
