CXXFLAGS = -L lib/ -I lib/ -lzmq -lredis3m -std=c++11
CXX = g++

broker :
	$(CXX) $(wildcard src/broker/*.cpp) -o broker $(CXXFLAGS)
