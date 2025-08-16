#include "HelpCommand.h"
#include "CommandFactory.h"

HelpCommand::HelpCommand(const std::vector<std::string>& args) {
    if (std::find(args.begin(), args.end(), "-h") != args.end()) {
        setFlag(HELP);
        clearFlag(DEFAULT);
    }
}

void HelpCommand::Execute(CommandEngine& cmdEngine) const {
    if (hasFlag(DEFAULT)) {
        for (const auto& pair : CommandFactory::listCommandRegistry()) {
            std::vector<std::string> args = { pair.first, "-h" };
            auto cmd = CommandFactory::createCommand(args);
            cmdEngine.printLine("---------- " + pair.first + " ----------");
            cmd->Execute(cmdEngine);
            cmdEngine.printLine("");
        }
    }
    else if (hasFlag(HELP)) {
        cmdEngine.printLine("Provides a list of commands you can use.");
    }
}