#include "trading_engine.h"

#include <unistd.h>


#include "logging.h"

using namespace trading_engine::utils;

namespace trading_engine::server {
void TradingEngine::run() {
    logging::log_info("Trading engine is running on " + _server_ip + ":" +
                      std::to_string(_server_port));
    register_routes();
    _app.loglevel(crow::LogLevel::Warning);
    _app.port(_server_port).bindaddr(_server_ip).multithreaded().run();

}

void TradingEngine::register_routes() {
    _app.route_dynamic("/").methods("GET"_method)([this](const crow::request& req) {
        return crow::response(200, "Hello, World!");
    });
    _app.route_dynamic("/shutdown").methods("POST"_method)([this](const crow::request& req) {
        stop();
        return crow::response(200, "Shutting down...");
    });
}

void TradingEngine::stop() {
    logging::log_warning("Trading engine is stopping");
    _app.stop();
}
}  // namespace trading_engine::server
