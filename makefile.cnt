DEPS= AsianOption.cpp PayOff/PayOffBridge.cpp Statistics/ConvergenceTable.cpp Statistics/Statistics.cpp Random/Random2.cpp Random/Arrays.cpp Random/Normals.cpp Random/ParkMiller.cpp Random/AntiThetic.cpp PayOff/PayOff4.cpp Option/ExoticBSEngine.cpp Option/PathDependentAsian.cpp Option/PathDependent.cpp Option/ExoticEngine.cpp utils/utils.cpp Parameters/Parameters.cpp
CFLAGS = --std=c++17
stock: $(DEPS)
	g++ -o optionprice $(DEPS) ${CFLAGS}