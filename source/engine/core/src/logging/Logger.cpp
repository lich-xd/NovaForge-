#include <core/logging/Logger.h>

#include <iostream>

namespace nova::core
{

std::mutex Logger::s_mutex;

void Logger::trace(std::string_view message)
{
    log(LogLevel::Trace, message);
}

void Logger::debug(std::string_view message)
{
    log(LogLevel::Debug, message);
}

void Logger::info(std::string_view message)
{
    log(LogLevel::Info, message);
}

void Logger::warning(std::string_view message)
{
    log(LogLevel::Warning, message);
}

void Logger::error(std::string_view message)
{
    log(LogLevel::Error, message);
}

void Logger::critical(std::string_view message)
{
    log(LogLevel::Critical, message);
}

void Logger::log(LogLevel level,
std::string_view message)
{
    std::lock_guard lock(s_mutex);

    std::cout
        << "["
        << toString(level)
        << "] "
        << message
        << '\n';
}

const char* Logger::toString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Trace:    return "TRACE";
        case LogLevel::Debug:    return "DEBUG";
        case LogLevel::Info:     return "INFO";
        case LogLevel::Warning:  return "WARNING";
        case LogLevel::Error:    return "ERROR";
        case LogLevel::Critical: return "CRITICAL";
        default:                 return "UNKNOWN";
    }
}

}