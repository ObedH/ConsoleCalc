#include "ExitCommand.h"

void ExitCommand::Execute(CommandEngine& cmdEngine) const {
	cmdEngine.exit();
};

std::string ExitCommand::getDescription() const {
	return "Exits the application.";
}