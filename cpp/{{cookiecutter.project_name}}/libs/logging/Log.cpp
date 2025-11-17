#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace logging {

std::shared_ptr<spdlog::logger> Log::s_consoleLogger;

void Log::init() {
    Log::s_consoleLogger = spdlog::stdout_color_mt("console");
    Log::s_consoleLogger->set_level(spdlog::level::info);
    Log::s_consoleLogger->set_pattern("[%H:%M:%S.%f](%^%l%$) %v");
}

Log::Log() { init(); }

}  // namespace logging