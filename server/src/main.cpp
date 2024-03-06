#include <cstdlib>

#include "logging.h"
#include "trading_engine.h"

using namespace trading_engine::server;
using namespace trading_engine::utils;

int main() {
    auto config = config::load_config("config.json");
    if (!config.has_value()) {
        logging::log_error("Failed to load config");
        return EXIT_FAILURE;
    }
    logging::log_info("Config loaded successfully");
    auto trading_engine = TradingEngine{std::move(*config)};
    config.reset();
    trading_engine.run();
    return EXIT_SUCCESS;
}
