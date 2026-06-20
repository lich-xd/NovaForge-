cmake_minimum_required(VERSION 3.21)

project(NovaForge)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(source/engine/core)

add_executable(NovaForge
app/main.cpp
)

target_link_libraries(NovaForge
PRIVATE
NovaCore
)
