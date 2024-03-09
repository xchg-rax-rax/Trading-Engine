#include "trading_engine.h"

#include <unistd.h>

#include "logging.h"
#include "nlohmann/json.hpp"
#include "order.h"
using json = nlohmann::json;

using namespace trading_engine::utils;
using namespace trading_engine::server::order_book;

namespace trading_engine::server {
void TradingEngine::run() {
    logging::log_info("Trading engine is running on " + _server_ip + ":" +
                      std::to_string(_server_port));
    register_routes();
    _app.loglevel(crow::LogLevel::Warning);
    _app.port(_server_port).bindaddr(_server_ip).multithreaded().run();
}

void TradingEngine::register_routes() {
    _app.route_dynamic("/").methods("GET"_method)(
        [this](const crow::request& req) {
            return crow::response(200, "Hello, World!");
    });
    _app.route_dynamic("/add_order")
        .methods("POST"_method)([this](const crow::request& req) {
            auto x = json::parse(req.body, nullptr, false);
            if (x.is_discarded()) {
                return crow::response(400, "Invalid JSON");
            }
            auto order = Order::from_json(x);
            if (!order) {
                return crow::response(400, "Invalid order");
            }
            order.value().debug_print();
            _order_book.add_order(order.value());
            return crow::response(200, "Order added");
    });
}

void TradingEngine::stop() {
    logging::log_warning("Trading engine is stopping");
    _app.stop();
}
}  // namespace trading_engine::server
