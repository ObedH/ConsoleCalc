#pragma once
#include "CommandEngine.h"

class Command {
protected:
	std::vector<std::string> output;
	bool correctSyntax = true;
public:
	~Command() = default;
	virtual void Execute(CommandEngine& ce) const = 0;
	virtual std::string getDescription() const = 0;
};