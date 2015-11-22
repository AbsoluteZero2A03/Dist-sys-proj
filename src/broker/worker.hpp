#include <redis3m/redis3m.hpp>
#include "cppzmq/zmq.hpp"
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include "connections.hpp"
#include "db_daemon.h"

class SkidooshBrokerTask {
    public:
        SkidooshBrokerTask() : ctx(1), frontend(ctx,ZMQ_ROUTER),backend(ctx,ZMQ_DEALER) {}; 
        enum { kMaxThread = 5 };
        void run();
    private:
        zmq::context_t ctx;
        zmq::socket_t frontend;
        zmq::socket_t backend;
        DatabaseDaemon daemon;
};

class SkidooshBrokerWorker {
    public:
        SkidooshBrokerWorker(zmq::context_t &c, int sock_type): ctx(c), wk_sck(ctx, sock_type) {};
        void work();
    private:
        zmq::context_t &ctx;
        zmq::socket_t wk_sck;
};
