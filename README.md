# OptionPricing

In this project, I try to implement an object oriented approach to Options Pricing. The idea is

- To encapsulate the key algorithms in a way that the code can be reused for various cases
- To seperate the interface from implementation so that future improvements in implementation don't break the interface
- To look at neat ways to achieve simplicity in code, hiding implementation details, so as to provide no chances for data corruption or unauthorized access.


## Issues with this approach

- As it stands, adding any new payoff methods (exotic options, digital option etc.) would require a change in the files Payoff1.h and Payoff1.cpp (adding more enums). But that would mean every other file that imports it must be recompiled. This can cause issues when either dealing with external software (say, the MC part has been imported from somewhere else, and cannot be recompiled), or it can be time consuming.
- We need a way to modify (add) behaviors to the payoff class, without changing the Payoff1.h file, and also not forcing dependant file recompilation.

## Adding Inheritance to PayOff Class

Now, in this version, I added extensibility to the PayOff class, so that we can address the two challenges
  - All Payoff classes are inherited from the base, which is not a usable class (because of a pure Virtual Function)
  - Additional PayOffs can be added without changing the base class, and the recompilation is no longer as expensive.
  - All payoffs can have their own parameters, and one payoff can be as complex as possible (a mix of several options, maybe) without modifying all other payoff classes.


There are still some challenges.

## Future Challenges

- For every payoff, there is an interface (a new Class for each payoff type). Can this be made easier? I specify an option type, that instantiates some class according to the name of the option, and the interface doesn't need to add logic for which payoff to initialize?
- What about the variation in the number of params for each payoff? Can something handle a varying list of params for each payoff type?


## Adding Option Class and Virtual Constructor for PayOff Attribute

- Now, I start to develop the object equivalence to the Option. It contains two attributes: the payOff and the expiry.
- The PayOff needs to be "Cloned" so that there are no issues with object change after assigning/ object deletion on scope change.
- Instead of the PayOff class, the Monte Carlo Simulation is not exposed to any payoff, and directly gets the Future Value from the option.


## Put Option Price from Call Option

- I used a neat tool from Arbitrage theory to get the put option price from the Spot and the call option price.
- Basically, you can replicate the portfolio of buying a call and selling a put, with the portfolio of a stock buy and a borrow from the bond market. Equating the prices, gives the price of the Put option.


## Parameters Class with Important Functions

- For important parameters like Interest Rate and Volatility, the Basic Monte Carlo Simulation assumes that these parameters are constant over the horizon.
- In the future, there could be further developments, with complex models being developed to assess the interest rate as a function of other parameters, basically not always a constant.
- Same for Volatility, there are complex models that can be implemented for the parameter.
- For the purposes of the Simulation, there are two important functions, the integral and the integral of the sqaure over the horizon for the parameter. These two methods can be implemented for each statistic.

## Statistics Class with Strategy Design Pattern

- Along with parameters, there are key statistics that are kept track of, for the purpose of calculating the option price. For something like the expected value, it's simply the calculation of a running sum and dividing it by the number of paths.

- But Some complex option prices like Asian options or American Options, we may need pathwise payoffs for the option. So we need two methods for our interface:
    - Dumping PayOff Results
    - Returning Required Statistics

- The implementation of how the statistics are stored/generated for each option/financial instrument is encapsulated within the strategy methods. To the user, only these two methods are provided.


## Wrapper Class and Template Programming in C++

- In this latest update, I've added a wrapper class so that any class initialized on top of it need not handle it's own memory management.
- This wrapper class works on top of any class, because it's written to work on a template class. It stores a inner pointer to the actual class variable, and provides pointer like access to the attributes of the class.
- Any future class can use the constructor of the wrapper class so that it can eventually work as a pointer to that class, and the destructor of the wrapper destroys the object on going out of scope.

