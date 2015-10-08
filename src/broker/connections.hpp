#include <redis3m/redis3m.hpp>
#include "json/json.hpp"
#include "cppzmq/zmq.hpp"
#include <map>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

using json = nlohmann::json;

#ifndef _SKIDOOSH_BROKER_CONNECTIONS_H
#define _SKIDOOSH_BROKER_CONNECTIONS_H

json recv_spec_msg(std::string);
void store_connection (json j);

#endif
