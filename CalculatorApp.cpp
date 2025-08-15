#include <string>
#include "Command.h"
#include "CalculatorApp.h"

CalculatorApp::CalculatorApp(IOFacade& io, CommandEngine& ce) : ioFacade(io), cmdEngine(ce) {
	isRunning = false;
}
CalculatorApp::~CalculatorApp() {
	
}

void CalculatorApp::run() {
	setup();
	isRunning = true;
	loop();
}

void CalculatorApp::setup() {
	ioFacade.setup();
}
void CalculatorApp::loop() {
	while (isRunning) {
		std::string inputLine = ioFacade.readLine();
		cmdEngine.parseAndRun(inputLine);
		ioFacade.printLines(cmdEngine.readOutputLines());
		ioFacade.flush();
	}
}
void CalculatorApp::requestExit() {
	isRunning = false;
}