#pragma once

#include <core/commands/ICommand.h>

#include <memory>
#include <vector>

namespace nova::core
{

class CommandManager
{
public:

    void executeCommand(
        std::unique_ptr<ICommand> command);

    void undo();

    bool canUndo() const noexcept;

private:

    std::vector<std::unique_ptr<ICommand>>
        m_history;
};

}