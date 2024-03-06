#include "trading_engine_server_config.h"

#include <fstream>

#include "logging.h"
#include "nlohmann/json.hpp"

using namespace trading_engine::utils;

using json = nlohmann::json;

namespace trading_engine::server::config {
std::optional<TradingEngineServerConfig> load_config(
    const std::string& config_file_path) {
    std::ifstream config_file(config_file_path);
    if (!config_file.is_open()) {
        return std::nullopt;
    }

    json config_json = json::parse(config_file, nullptr, false);
    if (config_json.is_discarded()) {
        logging::log_error("Failed to parse config file");
        return std::nullopt;
    }

    std::string debug_config = config_json.dump(4);
    logging::log_debug("Config file: \n" + debug_config);

    bool failed_to_parse = false;
    if (!config_json.contains("server_ip")) {
        logging::log_error("Config file does not contain server_ip");
        failed_to_parse = true;
    }

    if (!config_json.contains("server_port")) {
        logging::log_error("Config file does not contain server_port");
        failed_to_parse = true;
    }

    if (failed_to_parse) {
        logging::log_error("Failed to valid config file schema");
        return std::nullopt;
    }

    return TradingEngineServerConfig{
        .server_ip = config_json["server_ip"].get<std::string>(),
        .server_port = config_json["server_port"].get<uint16_t>()};
}
}  // namespace trading_engine::server::config
