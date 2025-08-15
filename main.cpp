#include "CalculatorApp.h"
#include "CommandEngine.h"
#include "IAppEvents.h"

int main()
{
	IOFacade io;
	CommandEngine ce;
	CalculatorApp app(io, ce);

	ce.setApplication(app);
	app.run();
	return 0;
}
