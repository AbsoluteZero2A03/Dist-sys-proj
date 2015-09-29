#include <zmq.hpp>
#include <map>
#include "json/json.hpp"
#include "connections.hpp"

int main () {
    
    std::map<std::string, zmq::socket_t *> curr_connections;
    zmq::context_t context(1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind("tcp://*:17773");

    while (true) {
        zmq::message_t request;
        recv_spec_msg(request, socket, &curr_connections);
    }
    
    return 0;
}
