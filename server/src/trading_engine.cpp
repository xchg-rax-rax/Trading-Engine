#include "trading_engine.h"

#include <unistd.h>

#include <iostream>

#include "logging.h"

using namespace trading_engine::utils;

namespace trading_engine::server {
void TradingEngine::run() {
    logging::log_info("Trading engine is running on " + _server_ip + ":" +
                      std::to_string(_server_port));
    while (true) {
        sleep(15);
        stop();
        break;
    }
}

void TradingEngine::stop() {
    logging::log_warning("Trading engine is stopping");
}
}  // namespace trading_engine::server
