CXXFLAGS = -L /usr/local/lib/ -I /usr/local/include/ -L lib/ -I lib/ -lzmq -lredis3m -lpthread -std=c++11
CXX = g++

broker :
	$(CXX) $(wildcard src/broker/*.cpp) -o broker $(CXXFLAGS)
