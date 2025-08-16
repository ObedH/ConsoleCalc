#include <string>
#include "Command.h"
#include "FileApp.h"

FileApp::FileApp(IOFacade& io, CommandEngine& ce) : ioFacade(io), cmdEngine(ce) {
	isRunning = false;
}
FileApp::~FileApp() {
	
}

void FileApp::run() {
	setup();
	isRunning = true;
	loop();
}

void FileApp::setup() {
	ioFacade.setup();
}
void FileApp::loop() {
	while (isRunning) {
		std::string inputLine = ioFacade.readLine();
		cmdEngine.parseAndRun(inputLine);
		ioFacade.printLines(cmdEngine.readOutputLines());
		ioFacade.flush();
	}
}
void FileApp::requestExit() {
	isRunning = false;
}