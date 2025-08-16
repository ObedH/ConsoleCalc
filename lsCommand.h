#pragma once
#include "Command.h"

class lsCommand : public Command
{
public:
	lsCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
};