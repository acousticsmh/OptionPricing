DEPS= SimpleMC3Main.cpp  PayOff/PayOff2.cpp PayOff/PayOff3.cpp MC/SimpleMC2.cpp  Random/Random1.cpp
stock: $(DEPS)
	g++ -o option $(DEPS)