#ifndef UTILS_H
#define UTILS_H

double phi(double x);

double black_scholes_price(double S_0, double sigma, double r, double T, double K);

double get_put_from_call(double S_0, double C, double K, double r, double T);

#endif
