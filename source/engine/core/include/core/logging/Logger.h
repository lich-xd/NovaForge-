#pragma once

#include <core/logging/LogLevel.h>

#include <mutex>
#include <string_view>

namespace nova::core
{

class Logger
{
public:

    static void trace(std::string_view message);

    static void debug(std::string_view message);

    static void info(std::string_view message);

    static void warning(std::string_view message);

    static void error(std::string_view message);

    static void critical(std::string_view message);

private:

    static void log(LogLevel level,
                    std::string_view message);

    static const char* toString(LogLevel level);

    static std::mutex s_mutex;
};

}