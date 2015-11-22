#include "db_daemon.hpp"

void DatabaseDaemon::work() {
    redis3m::connection::ptr_t conn = redis3m::connection::create();
    relay.connect("");
    while (true) {
        for (std::list<std::string>::iterator it = waiting.begin(); it != waiting.end(); ++it) {
            redis3m::reply r = conn->run(command("GET") << *it);
            if (r.integer() != 0) {
               // do something...         
               // need to figure out how this relay business works
            }
        }    
    }
}
