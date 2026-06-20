add_library(NovaCore STATIC

    src/application/CoreApplication.cpp
    src/modules/ModuleManager.cpp

    src/logging/Logger.cpp
)

target_include_directories(NovaCore
PUBLIC
    include
)