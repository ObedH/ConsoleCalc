#pragma once
#include <string>
#include "IOFacade.h"
#include "CommandEngine.h"
#include "IAppEvents.h"

class FileApp : IAppEvents
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
	FileApp(IOFacade& io, CommandEngine& ce);
	~FileApp();
	void run();
	void requestExit();
};

