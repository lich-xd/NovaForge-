#include <core/commands/CommandManager.h>

#include <core/logging/Logger.h>

namespace nova::core
{

void CommandManager::executeCommand(
    std::unique_ptr<ICommand> command)
{
    if (!command)
        return;

    Logger::info(
        std::string("Executing command: ")
        + std::string(command->getName()));

    command->execute();

    m_history.push_back(
        std::move(command));
}

void CommandManager::undo()
{
    if (m_history.empty())
        return;

    auto& command =
        m_history.back();

    Logger::info(
        std::string("Undo command: ")
        + std::string(command->getName()));

    command->undo();

    m_history.pop_back();
}

bool CommandManager::canUndo() const noexcept
{
    return !m_history.empty();
}

}