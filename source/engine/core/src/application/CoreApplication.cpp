#include <core/application/CoreApplication.h>
#include <core/logging/Logger.h>

namespace nova::core
{

bool CoreApplication::initialize()
{
    Logger::info("Nova Forge initializing");

    return m_moduleManager.initializeModules();
}

void CoreApplication::run()
{
    Logger::info("Nova Forge running");
}

void CoreApplication::shutdown()
{
    Logger::info("Nova Forge shutdown");

    m_moduleManager.shutdownModules();
}

}