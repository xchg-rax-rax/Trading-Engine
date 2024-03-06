#pragma once
#include <cstdint>
#include <optional>
#include <string>

namespace trading_engine::server::config {
struct TradingEngineServerConfig {
    std::string server_ip;
    uint16_t server_port;
};

std::optional<TradingEngineServerConfig> load_config(
    const std::string& config_file_path);
}  // namespace trading_engine::server::config
