#pragma once
#include <memory>
#include <functional>
#include <unordered_map>
#include <string>
#include "Command.h"
#include "AddCommand.h"
#include "SubCommand.h"
#include "MulCommand.h"
#include "DivCommand.h"
#include "ExitCommand.h"
#include "HelpCommand.h"
#include "UnknownCommand.h"

class CommandFactory {
private:
    //std::unordered_map<std::string, std::function<std::unique_ptr<Command>(const std::vector<std::string>&)>> commandRegistry;
    using CreatorFn = std::function<std::unique_ptr<Command>(const std::vector<std::string>&)>;

    static std::unordered_map<std::string, CreatorFn>& commandRegistry() {
        static std::unordered_map<std::string, CreatorFn> instance = {
            { "add",            [](const std::vector<std::string>& args) { return std::make_unique<AddCommand>(args); } },
            { "sub",            [](const std::vector<std::string>& args) { return std::make_unique<SubCommand>(args); } },
            { "mul",            [](const std::vector<std::string>& args) { return std::make_unique<MulCommand>(args); } },
            { "div",            [](const std::vector<std::string>& args) { return std::make_unique<DivCommand>(args); } },
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