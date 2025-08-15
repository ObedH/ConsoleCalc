#pragma once
#include "Command.h"

class ExitCommand : public Command
{
public:
	ExitCommand(const std::vector<std::string>& args) {};
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};