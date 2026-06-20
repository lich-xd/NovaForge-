add_library(NovaCore STATIC
src/application/CoreApplication.cpp
src/modules/ModuleManager.cpp
)

target_include_directories(NovaCore
PUBLIC
include
)
