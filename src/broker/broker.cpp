#include "cppzmq/zmq.hpp"
#include <map>
#include "json/json.hpp"
#include "connections.hpp"
#include "worker.hpp"
#include <thread>
#include <functional>

int main () {
    
    SkidooshBrokerTask btask;
    std::thread th1(std::bind(&SkidooshBrokerTask::run,&btask));
    th1.detach();
    return 0;
}
