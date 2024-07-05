#ifndef VANILLA_2_H
#define VANILLA_2_H
#include <PayOffBridge.h>
class VanillaOption
{
public:
    VanillaOption(const PayOffBridge &
                      ThePayOff_,
                  double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;

private:
    double Expiry;
    PayOffBridge ThePayOff;
};
#endif