DEPS= SimpleMC3.cpp  PayOff/PayOff2.cpp MC/SimpleMC2.cpp  Random/Random1.cpp
stock: $(DEPS)
	g++ -o option $(DEPS)