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


void store_connection(json j) {
    redis3m::connection::ptr_t conn = redis3m::connection::create();
    std::string ip = j["ip"];
    std::string whole_thing = j.dump();

    conn->run(redis3m::command("SET") << ip << whole_thing);
}
