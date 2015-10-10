#include <list>
#include <string>
#include "json/json.hpp"
#include "cppzmq/zmq.hpp"

class DatabaseDaemon {
    public:
        DatabaseDaemon();
        void work();
    private:
        zmq::socket_t relay;
        std::list<std::string> waiting;
};
