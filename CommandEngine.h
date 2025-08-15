#pragma once
#include <string>
#include <memory>
#include <vector>

class Command;
class CalculatorApp;

class CommandEngine
{
private:
	std::vector<std::string> output;
	CalculatorApp* app = nullptr;
public:

private:

public:
	void setApplication(CalculatorApp& events);
	std::unique_ptr<Command> parse(const std::string& line);
	void execute(std::unique_ptr<Command> cmd);
	void parseAndRun(const std::string& line);
	void printLine(const std::string& line);
	void exit();
	std::vector<std::string> readOutputLines();
};