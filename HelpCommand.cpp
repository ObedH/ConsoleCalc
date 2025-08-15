#include "HelpCommand.h"
#include "CommandFactory.h"

void HelpCommand::Execute(CommandEngine& cmdEngine) const {
    for (const auto& pair : CommandFactory::listCommandRegistry()) {
        std::vector<std::string> args = {pair.first};
        auto cmd = CommandFactory::createCommand(args);
        cmdEngine.printLine(pair.first + " - " + cmd->getDescription());
    }
}

std::string HelpCommand::getDescription() const {
    return "Provides a list of commands you can use.";
}