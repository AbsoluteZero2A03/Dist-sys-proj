#include "worker.hpp"

void SkidooshBrokerTask::run() {
    while (true) {

    }
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
    wk_sck.connect("inproc://backend");        
    try {
        while (true) {
            zmq::message_t identity;
            zmq::message_t msg;
            zmq::message_t copied_id;
            zmq::message_t copied_msg;
            std::string rq_str;
            wk_sck.recv(&identity);
            wk_sck.recv(&msg);

            rq_str = std::string(static_cast<char *>(msg.data()),msg.size());
            copied_id.copy(&identity);
            copied_msg.copy(&msg);
        }
    } catch (std::exception &e) {}
}
