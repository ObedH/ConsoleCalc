#include "ExitCommand.h"

ExitCommand::ExitCommand(const std::vector<std::string>& args) {
	if (std::find(args.begin(), args.end(), "-h") != args.end()) {
		setFlag(HELP);
		clearFlag(DEFAULT);
	}
}

void ExitCommand::Execute(CommandEngine& cmdEngine) const {
	if (hasFlag(DEFAULT)){
		cmdEngine.exit();
	}
	else if (hasFlag(HELP)) {
		cmdEngine.printLine("Exits the application.");
	}
}