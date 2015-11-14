#include "connections.hpp"
using json = nlohmann::json;
json recv_spec_msg(std::string req) { 
    std::cout << "storing " << req << std::endl;
    try {
        std::stringstream ss;
        ss << req;
        json j;
        ss >> j;
        store_connection(j);
        return j;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return {};
    }
}

// store connections in a redis
void store_connection(json j) {
    try { 
        redis3m::connection::ptr_t conn = redis3m::connection::create();
        std::cout << "connection signal " << j << std::endl;
        std::string name = j["name"];
        std::cout << "name: " << name << std::endl;
        std::string whole_thing = j.dump();

        conn->run(redis3m::command("SET") << name << whole_thing);
        std::cout << "success" << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// delete a connection on disconnect
void delete_connection(json j) {
    redis3m::connection::ptr_t conn = redis3m::connection::create();
    std::string name = j["name"];
    redis3m::reply r = conn->run(redis3m::command("DEL") << name);
}
