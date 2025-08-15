#include <cmath>
#include "DivCommand.h"
#include "utils.h"

DivCommand::DivCommand(const std::vector<std::string>& args) {
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
	if (b == 0) {
		correctSyntax = false;
		dbz = true;
	}
	x = a;
	y = b;
}

void DivCommand::Execute(CommandEngine& cmdEngine) const {
	if (!correctSyntax) {
		if (dbz) {
			cmdEngine.printLine("Cannot divide by zero.");
			return;
		}
		cmdEngine.printLine("Usage:\ndiv <number> <number>");
		return;
	}
	cmdEngine.printLine(StringUtils::toString(x - y));
};

std::string DivCommand::getDescription() const {
	return "Divides two numbers.";
}