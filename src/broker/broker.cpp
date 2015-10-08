#include "cppzmq/zmq.hpp"
#include <map>
#include "json/json.hpp"
#include "connections.hpp"
#include "worker.hpp"
#include <thread>
#include <functional>

int main () {
    
    std::map<std::string, zmq::socket_t *> curr_connections;
    SkidooshBrokerTask btask;
    std::thread th1(std::bind(&SkidooshBrokerTask::run, &btask));
    
    return 0;
}
