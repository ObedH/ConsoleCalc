#include <cmath>
#include "SubCommand.h"
#include "utils.h"

SubCommand::SubCommand(const std::vector<std::string>& args) {
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

void SubCommand::Execute(CommandEngine& cmdEngine) const {
	if (!correctSyntax) {
		cmdEngine.printLine("Usage:\nsub <number> <number>");
		return;
	}
	cmdEngine.printLine(StringUtils::toString(x - y));
};

std::string SubCommand::getDescription() const {
	return "Subtracts two numbers.";
}