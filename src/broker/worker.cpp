#include "worker.hpp"

void SkidooshBrokerTask::run() {
    frontend.bind("tcp://*:20401");
    backend.bind("inproc://backend");
}

