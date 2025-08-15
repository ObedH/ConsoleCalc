#pragma once
#include <string>
#include <iostream>
#include <vector>

class IOFacade
{
private:

public:

private:

public:
	void setup();
	std::string readLine();
	void printLine(const std::string& line);
	void printLines(const std::vector<std::string>& lines);
	void flush();
};

