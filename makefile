DEPS= stock.cpp Random1.cpp
stock: $(DEPS)
	g++ -o stock $(DEPS)