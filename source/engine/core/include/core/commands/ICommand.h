#pragma once

#include <string_view>

namespace nova::core
{

class ICommand
{
public:

    virtual ~ICommand() = default;

    virtual void execute() = 0;

    virtual void undo() = 0;

    virtual std::string_view getName() const noexcept = 0;
};

}