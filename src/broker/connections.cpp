#include "connections.hpp"
using json = nlohmann::json;
// Checks if it's a valid message
json recv_spec_msg(zmq::socket_t * socket) { 
    zmq::message_t request;
    socket->recv(&request);
    try {
        std::string rpl = std::string(static_cast<char *>(request.data()),request.size());
        json j = json(rpl);
        return j;
    } catch (std::exception& e) {
        json j = {
            {"error", e.what()}
        };
        return j;
    }
}


