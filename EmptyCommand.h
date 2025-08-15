#pragma once
#include "Command.h"

class EmptyCommand : public Command
{
public:
	EmptyCommand() {};
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};