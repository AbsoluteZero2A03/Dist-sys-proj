#include "hiredis/hiredis.h"
#include "json/json.hpp"
#include <zmq.hpp>
#include <exception>
#include <string>

using json = nlohmann::json;

#ifndef _SKIDOOSH_BROKER_CONNECTIONS_H
#define _SKIDOOSH_BROKER_CONNECTIONS_H

json recv_spec_msg(zmq::socket_t * socket);

#endif
