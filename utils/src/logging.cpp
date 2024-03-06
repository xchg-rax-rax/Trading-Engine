#include "logging.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <future>

namespace trading_engine::utils::logging {

    void log(const std::string& message, LogLevel level) {
        auto _ = std::async(std::launch::async, log_sync, message, level);
    }

    void log_sync(const std::string message, LogLevel level) {
        static std::mutex log_mutex;
        std::lock_guard<std::mutex> lock(log_mutex);
        std::string level_str;
        switch (level) {
            case LogLevel::DEBUG:
                level_str = "[?] DEBUG"; 
                break;
            case LogLevel::INFO:
                level_str = "[-] INFO";
                break;
            case LogLevel::WARNING:
                level_str = "[*] WARNING";
                break;
            case LogLevel::ERROR:
                level_str = "[!] ERROR";
                break;
        }
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        auto data_time_str = std::put_time(std::localtime(&now_time), "%Y-%m-%d %X");
        std::cerr << data_time_str << "\t"<< level_str << ": " << message << std::endl;
    }
    void log_debug(const std::string& message) {
        auto _ = std::async(std::launch::async, log, message, LogLevel::DEBUG);
    }
    void log_info(const std::string& message) {
        auto _ = std::async(std::launch::async, log, message, LogLevel::INFO);
    }
    void log_warning(const std::string& message) {
        auto _ = std::async(std::launch::async, log, message, LogLevel::WARNING);
    }
    void log_error(const std::string& message) {
        auto _ = std::async(std::launch::async, log, message, LogLevel::ERROR);
    }
}  // namespace trading_engine::utils::logging
