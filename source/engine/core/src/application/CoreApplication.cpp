#include <core/application/CoreApplication.h>
#include <core/logging/Logger.h>
#include <core/events/EventBus.h>
#include <core/events/ApplicationStartedEvent.h>

namespace nova::core
{

bool CoreApplication::initialize()
{
    Logger::info("Nova Forge initializing");

    ApplicationStartedEvent event;
    
    EventBus::publish(event);

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