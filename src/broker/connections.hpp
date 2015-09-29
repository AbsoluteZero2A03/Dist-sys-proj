#include <redis3m/redis3m.hpp>
#include "json/json.hpp"
#include <zmq.hpp>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

using json = nlohmann::json;

#ifndef _SKIDOOSH_BROKER_CONNECTIONS_H
#define _SKIDOOSH_BROKER_CONNECTIONS_H

json recv_spec_msg(zmq::socket_t * socket);
void store_connection (json j);

#endif
