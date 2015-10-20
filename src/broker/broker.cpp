#include "cppzmq/zmq.hpp"
#include <map>
#include "json/json.hpp"
#include "connections.hpp"
#include "worker.hpp"
#include <thread>
#include <functional>

int main () {
    
    SkidooshBrokerTask btask;
    btask.run();
    return 0;
}
