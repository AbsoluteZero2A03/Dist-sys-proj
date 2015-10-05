#include "worker.hpp"

void SkidooshBrokerTask::run() {
    frontend.bind("tcp://*:20401");
    backend.bind("inproc://backend");
    
    std::vector<SkidooshBrokerWorker *> workers;
    std::vector<std::thread *> worker_threads;

    for (int i=0; i<kMaxThread; ++i) {
        workers.push_back(new SkidooshBrokerWorker(ctx,ZMQ_DEALER));
        worker_threads.push_back(new std::thread(std::bind(&SkidooshBrokerWorker::work, workers[workers.size()-1])));
        worker_threads[worker_threads.size()-1]->detach();
    }

    try {
        zmq::proxy(&frontend,&backend,nullptr);
    } catch (std::exception &e) {

    }

    for (int i=0;i<kMaxThread; ++i) {
        delete workers[i];
        delete worker_threads[i];
    }
}

void SkidooshBrokerWorker::work() {
    
}


