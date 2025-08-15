#include <cmath>
#include "AddCommand.h"
#include "utils.h"

AddCommand::AddCommand(const std::vector<std::string>& args) {
	if (args.size() != 3) {
		correctSyntax = false;
		return;
	}
	double a = StringUtils::toDouble(args[1]);
	double b = StringUtils::toDouble(args[2]);
	if (std::isnan(a) || std::isnan(b)) {
		correctSyntax = false;
		return;
	}
	x = a;
	y = b;
}

void AddCommand::Execute(CommandEngine& cmdEngine) const {
	if (!correctSyntax) {
		cmdEngine.printLine("Usage:\nadd <number> <number>");
		return;
	}
	cmdEngine.printLine(StringUtils::toString(x + y));
};

std::string AddCommand::getDescription() const {
	return "Adds two numbers together.";
}