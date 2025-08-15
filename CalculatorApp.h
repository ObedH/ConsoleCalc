#pragma once
#include <string>
#include "IOFacade.h"
#include "CommandEngine.h"
#include "IAppEvents.h"

class CalculatorApp : IAppEvents
{
private:
	IOFacade& ioFacade;
	CommandEngine& cmdEngine;
	bool isRunning;
public:

private:
	void setup();
	void loop();
public:
	CalculatorApp(IOFacade& io, CommandEngine& ce);
	~CalculatorApp();
	void run();
	void requestExit();
};

