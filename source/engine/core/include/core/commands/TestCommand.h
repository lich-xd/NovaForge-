#pragma once

#include <core/commands/ICommand.h>

#include <core/logging/Logger.h>

namespace nova::core
{

class TestCommand final
    : public ICommand
{
public:

    void execute() override
    {
        Logger::info(
            "TestCommand executed");
    }

    void undo() override
    {
        Logger::info(
            "TestCommand undone");
    }

    std::string_view
    getName() const noexcept override
    {
        return "TestCommand";
    }
};

}