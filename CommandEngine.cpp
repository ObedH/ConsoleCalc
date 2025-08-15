#include <iostream>
#include "CommandEngine.h"
#include "CommandFactory.h"
#include "CalculatorApp.h"
#include "utils.h"

void CommandEngine::setApplication(CalculatorApp& app) {
	this->app = &app;
}

void CommandEngine::parseAndRun(const std::string& line) {
	execute(parse(line));
}

std::unique_ptr<Command> CommandEngine::parse(const std::string& line) {
	std::vector<std::string> keywords = StringUtils::split(line, " ");
	auto cmd = CommandFactory::createCommand(keywords);
	return std::move(cmd);
}

void CommandEngine::execute(std::unique_ptr<Command> cmd) {
	if (cmd == nullptr) {
		output.push_back("");
		return;
	}
	cmd->Execute(*this);
}

void CommandEngine::printLine(const std::string& line) {
	output.push_back(line);
}

void CommandEngine::exit() {
	app->requestExit();
}

std::vector<std::string> CommandEngine::readOutputLines() {
	auto out = output;
	output.clear();
	return out;
}