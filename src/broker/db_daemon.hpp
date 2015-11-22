#include <list>
#include <string>
#include "json/json.hpp"
#include "cppzmq/zmq.hpp"
#include <redis3m/redis3m.hpp> 


class DatabaseDaemon {
    public:
        DatabaseDaemon(zmq::context_t &c, int sock_type): ctx(c), relay(ctx,sock_type) {};
        void work();
    private:
        zmq::context_t &ctx;
        zmq::socket_t relay;
        std::list<std::string> waiting;
};
