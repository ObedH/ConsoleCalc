#pragma once
#include "Command.h"

class UnknownCommand : public Command
{
public:
	UnknownCommand(const std::vector<std::string>& args) {};
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};