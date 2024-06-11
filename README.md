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
