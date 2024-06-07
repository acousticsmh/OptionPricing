DEPS= MC2.cpp  PayOff1.cpp SimpleMC.cpp  Random1.cpp
stock: $(DEPS)
	g++ -o option $(DEPS)