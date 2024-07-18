DEPS= MC5Main.cpp PayOff/PayOffBridge.cpp PayOff/PayOff4.cpp MC/SimpleMC5.cpp Option/Vanilla2.cpp  Random/Random1.cpp utils/utils.cpp Parameters/Parameters.cpp Statistics/Statistics.cpp
CFLAGS = --std=c++17
stock: $(DEPS)
	g++ -o optionprice $(DEPS) ${CFLAGS}