#pragma once
#include <memory>
#include <functional>
#include <unordered_map>
#include <string>
#include "Command.h"
#include "ExitCommand.h"
#include "lsCommand.h"
#include "HelpCommand.h"
#include "UnknownCommand.h"

class CommandFactory {
private:
    //std::unordered_map<std::string, std::function<std::unique_ptr<Command>(const std::vector<std::string>&)>> commandRegistry;
    using CreatorFn = std::function<std::unique_ptr<Command>(const std::vector<std::string>&)>;

    static std::unordered_map<std::string, CreatorFn>& commandRegistry() {
        static std::unordered_map<std::string, CreatorFn> instance = {
            { "ls",             [](const std::vector<std::string>& args) { return std::make_unique<lsCommand>(args); } },
            { "exit",           [](const std::vector<std::string>& args) { return std::make_unique<ExitCommand>(args); } },
            { "help",           [](const std::vector<std::string>& args) { return std::make_unique<HelpCommand>(args); } },
            { "unknown",        [](const std::vector<std::string>& args) { return std::make_unique<UnknownCommand>(args); } }
        };
        return instance;
    }
public:
    static std::unique_ptr<Command> createCommand(const std::vector<std::string>& input);
    static std::unordered_map<std::string, CreatorFn> listCommandRegistry() { return commandRegistry(); };
};