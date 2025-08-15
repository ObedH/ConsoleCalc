#include <cmath>
#include "MulCommand.h"
#include "utils.h"

MulCommand::MulCommand(const std::vector<std::string>& args) {
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

void MulCommand::Execute(CommandEngine& cmdEngine) const {
	if (!correctSyntax) {
		cmdEngine.printLine("Usage:\nmul <number> <number>");
		return;
	}
	cmdEngine.printLine(StringUtils::toString(x * y));
};

std::string MulCommand::getDescription() const {
	return "Multiplies two numbers.";
}