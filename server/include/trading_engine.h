#pragma once

#include <cstdint>
#include <string>

#include "crow.h"

#include "order_book.h"
#include "trading_engine_server_config.h"

using namespace trading_engine::server::config;
using namespace trading_engine::server::order_book;

namespace trading_engine::server {
class TradingEngine {
   public:
    TradingEngine(TradingEngineServerConfig trading_engine_config)
        : _server_ip(trading_engine_config.server_ip),
          _server_port(trading_engine_config.server_port){};

    void run();
    void stop();

   private:
    const std::string _server_ip;
    const uint16_t _server_port;
    crow::SimpleApp _app;
    OrderBook _order_book;


    void register_routes();
};
}  // namespace trading_engine::server
