#pragma once
#include "Command.h"

class EmptyCommand : public Command
{
public:
	EmptyCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
};