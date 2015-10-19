#include <redis3m/redis3m.hpp>
#include "cppzmq/zmq.hpp"
#include <vector>
#include <functional>
#include <thread>
#include "connections.hpp"

class SkidooshBrokerTask {
    public:
        SkidooshBrokerTask() : ctx(1), frontend(ctx,ZMQ_ROUTER),backend(ctx,ZMQ_DEALER) {}; 
        enum { kMaxThread = 5 };
        void run();
    private:
        zmq::context_t ctx;
        zmq::socket_t frontend;
        zmq::socket_t backend;
};

class SkidooshBrokerWorker {
    public:
        SkidooshBrokerWorker(zmq::context_t &c, int sock_type): ctx(c), wk_sck(ctx, sock_type) {};
        void work();
    private:
        zmq::context_t &ctx;
        zmq::socket_t wk_sck;
};
