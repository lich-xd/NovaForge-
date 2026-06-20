#pragma once
#include <string_view>

/*
 * IModule is the base class for all modules.
 * It provides a common interface for all modules to inherit from.
 * It is used to ensure that all modules have a consistent interface.
 */


namespace nova::core
{

    class IModule
    {
    public:
        virtual ~IModule() = default;
        virtual bool initialize() = 0;
        virtual void shutdown() = 0;
        virtual std::string_view getName() const noexcept = 0;
    };

}
