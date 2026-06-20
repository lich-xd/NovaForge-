#include <core/application/CoreApplication.h>

#include <core/events/EventBus.h>
#include <core/events/ApplicationStartedEvent.h>

#include <core/logging/Logger.h>

int main()
{
    nova::core::EventBus::subscribe
    <
        nova::core::ApplicationStartedEvent
    >(
        [](const auto&)
        {
            nova::core::Logger::info(
                "ApplicationStartedEvent received");
        });

    nova::core::CoreApplication app;

    if (!app.initialize())
        return -1;

    app.run();

    app.shutdown();

    return 0;
}