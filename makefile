DEPS= VanillaMC.cpp PayOff/PayOff4.cpp Option/Vanilla.cpp MC/SimpleMC3.cpp  Random/Random1.cpp utils/utils.cpp
stock: $(DEPS)
	g++ -o optionprice $(DEPS)