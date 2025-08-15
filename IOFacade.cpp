#include "IOFacade.h"

void IOFacade::setup() {
	std::cout << ">";
}

std::string IOFacade::readLine() {
	std::string line;
	std::getline(std::cin, line);
	return line;
}

void IOFacade::printLine(const std::string& line) {
	std::cout << line << "\n";
}
void IOFacade::flush() {
	std::cout << ">";
}

void IOFacade::printLines(const std::vector<std::string>& lines) {
	for (std::string line : lines) {
		printLine(line);
	}
}