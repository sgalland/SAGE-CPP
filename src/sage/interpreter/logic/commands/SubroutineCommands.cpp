#include "SubroutineCommands.h"

void SubroutingCommands::call(uint8_t resourceID)
{
	LogicProcessor logicProcessor;
	logicProcessor.Execute(resourceID);
}

void SubroutingCommands::call_v(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	LogicProcessor logicProcessor;
	logicProcessor.Execute(resourceID);
}
