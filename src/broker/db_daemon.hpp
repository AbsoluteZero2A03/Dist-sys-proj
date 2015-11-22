#include <list>
#include <string>
#include "json/json.hpp"
#include "cppzmq/zmq.hpp"


class DatabaseDaemon {
    public:
        DatabaseDaemon(zmq::context_t &c, int sock_type): ctx(c), relay(ctx,sock_type) {};
        void work();
    private:
        zmq::socket_t relay;
        std::list<std::string> waiting;
};
