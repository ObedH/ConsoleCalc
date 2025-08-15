#pragma once
#include "Command.h"

class DivCommand : public Command
{
private:
	double x, y;
	bool dbz = false;
public:
	DivCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
	std::string getDescription() const override;
};