#include "connections.hpp"
using json = nlohmann::json;
json recv_spec_msg(std::string req) { 
    try {
        json j = json(req);
        store_connection(j);
        return j;
    } catch (std::exception& e) {
        json j = {
            {"error", e.what()}
        };
        return j;
    }
}

// store connections in a redis
void store_connection(json j) {
    redis3m::connection::ptr_t conn = redis3m::connection::create();
    std::string ip = j["ip"];
    std::string whole_thing = j.dump();

    conn->run(redis3m::command("SET") << ip << whole_thing);
    std::cout << "success" << std::endl;
}

// delete a connection on disconnect
void delete_connection(json j) {
    redis3m::connection::ptr_t conn = redis3m::connection::create();
    std::string ip = j["ip"];
    redis3m::reply r = conn->run(redis3m::command("DEL") << ip);
}
