# OptionPricing

In this project, I try to implement an object oriented approach to Options Pricing. The idea is

- To encapsulate the key algorithms in a way that the code can be reused for various cases
- To seperate the interface from implementation so that future improvements in implementation don't break the interface
- To look at neat ways to achieve simplicity in code, hiding implementation details, so as to provide no chances for data corruption or unauthorized access.


## Issues with this approach

- As it stands, adding any new payoff methods (exotic options, digital option etc.) would require a change in the files Payoff1.h and Payoff1.cpp (adding more enums). But that would mean every other file that imports it must be recompiled. This can cause issues when either dealing with external software (say, the MC part has been imported from somewhere else, and cannot be recompiled), or it can be time consuming.
- We need a way to modify (add) behaviors to the payoff class, without changing the Payoff1.h file, and also not forcing dependant file recompilation.