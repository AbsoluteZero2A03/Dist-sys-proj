#include "cppzmq/zmq.hpp"
#include <map>
#include "json/json.hpp"
#include "connections.hpp"
#include "worker.hpp"

int main () {
    
    std::map<std::string, zmq::socket_t *> curr_connections;
    SkidooshBrokerTask btask;
    btask.run();
    return 0;
}
