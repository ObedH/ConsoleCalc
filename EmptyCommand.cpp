#include "EmptyCommand.h"

void EmptyCommand::Execute(CommandEngine& cmdEngine) const {
	cmdEngine.printLine("");
};

std::string EmptyCommand::getDescription() const {
	return "Represents an empty command.";
}