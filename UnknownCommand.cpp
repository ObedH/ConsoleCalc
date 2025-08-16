#include "UnknownCommand.h"

UnknownCommand::UnknownCommand(const std::vector<std::string>& args) {
	if (std::find(args.begin(), args.end(), "-h") != args.end()) {
		setFlag(HELP);
		clearFlag(DEFAULT);
	}
}

void UnknownCommand::Execute(CommandEngine& cmdEngine) const {
	if (hasFlag(DEFAULT)) {
		cmdEngine.printLine("Unknown Command.");
	}
	else if (hasFlag(HELP)) {
		cmdEngine.printLine("Represents an unknown command.");
	}
};