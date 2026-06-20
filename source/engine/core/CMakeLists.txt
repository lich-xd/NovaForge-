add_library(NovaCore STATIC

    src/application/CoreApplication.cpp
    src/modules/ModuleManager.cpp
    src/logging/Logger.cpp
    src/events/EventBus.cpp
)

target_include_directories(NovaCore
PUBLIC
    include
)