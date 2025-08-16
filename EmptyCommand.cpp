#include "EmptyCommand.h"

EmptyCommand::EmptyCommand(const std::vector<std::string>& args) {
	if (std::find(args.begin(), args.end(), "-h") != args.end()) {
		setFlag(HELP);
		clearFlag(DEFAULT);
	}
}

void EmptyCommand::Execute(CommandEngine& cmdEngine) const {
	if (hasFlag(DEFAULT)) {
		cmdEngine.printLine("");
	}
	else if (hasFlag(HELP)) {
		cmdEngine.printLine("Represents an empty command.");
	}
};