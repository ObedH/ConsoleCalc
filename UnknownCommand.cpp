#include "UnknownCommand.h"

void UnknownCommand::Execute(CommandEngine& cmdEngine) const {
	cmdEngine.printLine("Unknown Command.");
};
std::string UnknownCommand::getDescription() const {
	return "Represents an unknown command.";
}