#pragma once
#include <string>
#include <memory>
#include <vector>

class Command;
class FileApp;

class CommandEngine
{
private:
	std::vector<std::string> output;
	FileApp* app = nullptr;
public:

private:

public:
	void setApplication(FileApp& events);
	std::unique_ptr<Command> parse(const std::string& line);
	void execute(std::unique_ptr<Command> cmd);
	void parseAndRun(const std::string& line);
	void printLine(const std::string& line);
	void exit();
	std::vector<std::string> readOutputLines();
};