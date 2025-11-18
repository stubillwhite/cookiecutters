#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#include <spdlog/spdlog.h>

namespace logging {

/**
 * @brief Log class for initializing and managing the logger.
 */
class Log {
   public:
    Log();
    void init();
    inline static std::shared_ptr<spdlog::logger>& getConsoleLogger()    { return s_consoleLogger; };

   private:
    static std::shared_ptr<spdlog::logger> s_consoleLogger;
};

}  // namespace logging

#define LOG_DEBUG(...) logging::Log::getConsoleLogger()->debug(__VA_ARGS__)
#define LOG_TRACE(...) logging::Log::getConsoleLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) logging::Log::getConsoleLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) logging::Log::getConsoleLogger()->warning(__VA_ARGS__)
#define LOG_ERROR(...) logging::Log::getConsoleLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) logging::Log::getConsoleLogger()->critical(__VA_ARGS__)

#pragma clang diagnostic pop
