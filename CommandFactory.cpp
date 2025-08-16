#include "CommandFactory.h"
#include "ExitCommand.h"
#include "EmptyCommand.h"
#include "UnknownCommand.h"
#include "utils.h"

using CreatorFn = std::function<std::unique_ptr<Command>(const std::vector<std::string>&)>;

std::unique_ptr<Command> CommandFactory::createCommand(const std::vector<std::string>& input) {
    if (input.empty()) return nullptr;

    auto it = commandRegistry().find(input[0]);
    if (it != commandRegistry().end()) {
        return it->second(input);
    }
    return commandRegistry().find("unknown")->second(input);
}