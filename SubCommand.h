#pragma once
#include "Command.h"

class SubCommand : public Command
{
private:
	double x, y;
public:
	SubCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};