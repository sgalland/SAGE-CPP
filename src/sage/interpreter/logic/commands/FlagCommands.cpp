#include "FlagCommands.h"

void FlagCommands::set(uint8_t flagID)
{
	AgiInterpreter::flags[flagID] = 1;
}

void FlagCommands::setv(uint8_t variableID)
{
	uint8_t flagID = AgiInterpreter::variables[variableID];
	AgiInterpreter::flags[flagID] = 1;
}

void FlagCommands::reset(uint8_t flagID)
{
	AgiInterpreter::flags[flagID] = 0;
}

void FlagCommands::resetv(uint8_t variableID)
{
	uint8_t flagID = AgiInterpreter::variables[variableID];
	AgiInterpreter::flags[flagID] = 0;
}

void FlagCommands::toggle(uint8_t flagID)
{
	if (AgiInterpreter::flags[flagID] == 0) 
		AgiInterpreter::flags[flagID] = 1;
	else 
		AgiInterpreter::flags[flagID] = 0;
}

void FlagCommands::togglev(uint8_t variableID)
{
	uint8_t flagID = AgiInterpreter::variables[variableID];

	if (AgiInterpreter::flags[flagID] == 0)
		AgiInterpreter::flags[flagID] = 1;
	else
		AgiInterpreter::flags[flagID] = 0;
}
