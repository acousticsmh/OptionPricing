DEPS= TreeMain.cpp PayOff/PayOffForward.cpp PayOff/PayOffBridge.cpp PayOff/PayOff4.cpp Random/Arrays.cpp Random/Normals.cpp Random/Random2.cpp Random/ParkMiller.cpp Random/AntiThetic.cpp  Option/TreeAmerican.cpp Option/TreeEuropean.cpp Option/TreeProducts.cpp Option/BinomialTree.cpp utils/utils.cpp Parameters/Parameters.cpp
CFLAGS = --std=c++17
stock: $(DEPS)
	g++ -o treeoption $(DEPS) ${CFLAGS}