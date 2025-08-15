#pragma once
#include "Command.h"

class MulCommand : public Command
{
private:
	double x, y;
public:
	MulCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};