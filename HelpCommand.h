#pragma once
#include "Command.h"

class CommandFactory;

class HelpCommand : public Command
{
private:
public:
	HelpCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
};