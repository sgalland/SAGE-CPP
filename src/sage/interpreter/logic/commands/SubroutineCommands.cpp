#include "SubroutineCommands.h"
#include "../../AgiInterpreter.h"
#include "../LogicProcessor.h"

void sage::agi::SubroutineCommands::call(uint8_t resourceID)
{
	LogicProcessor logicProcessor;
	logicProcessor.Execute(resourceID);
}

void sage::agi::SubroutineCommands::call_v(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	LogicProcessor logicProcessor;
	logicProcessor.Execute(resourceID);
}

void sage::agi::SubroutineCommands::set_scan_start(int startPosition)
{
	// sets the entry point when starting a logic
	AgiInterpreter::logicProcessor.logicIndex = startPosition;
}

void sage::agi::SubroutineCommands::reset_scan_start()
{
	// reset scanning to the start of the logic
	AgiInterpreter::logicProcessor.logicIndex = 0;
}
