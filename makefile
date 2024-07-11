DEPS= SimpleMC4Main.cpp PayOff/PayOffBridge.cpp PayOff/PayOff4.cpp MC/SimpleMC4.cpp Option/Vanilla2.cpp  Random/Random1.cpp utils/utils.cpp Parameters/Parameters.cpp
stock: $(DEPS)
	g++ -o optionprice $(DEPS)