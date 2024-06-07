DEPS= MC2.cpp  PayOff/PayOff1.cpp MC/SimpleMC.cpp  Random/Random1.cpp
stock: $(DEPS)
	g++ -o option $(DEPS)