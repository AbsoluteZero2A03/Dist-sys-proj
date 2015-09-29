#include <redis3m/redis3m.hpp>
#include "json/json.hpp"
#include <zmq.hpp>
#include <map>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

using json = nlohmann::json;

#ifndef _SKIDOOSH_BROKER_CONNECTIONS_H
#define _SKIDOOSH_BROKER_CONNECTIONS_H

json recv_spec_msg(zmq::message_t request, zmq::socket_t socket, std::map<std::string, zmq::socket_t *> * curr);
void store_connection (json j);

#endif
