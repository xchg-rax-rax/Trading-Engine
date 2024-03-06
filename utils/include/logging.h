#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace trading_engine::utils::logging {
//
enum LogLevel : uint32_t { DEBUG, INFO, WARNING, ERROR };

void log(const std::string& message, LogLevel level);
void log_sync(const std::string message, LogLevel level);

void log_debug(const std::string& message);
void log_info(const std::string& message);
void log_warning(const std::string& message);
void log_error(const std::string& message);

}  // namespace trading_engine::utils::logging
