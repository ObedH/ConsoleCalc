#pragma once
#include "Command.h"

class AddCommand : public Command
{
private:
	double x, y;
public:
	AddCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};