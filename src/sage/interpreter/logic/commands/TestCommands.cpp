#include "TestCommands.h"



bool sage::agi::TestCommands::equaln(uint8_t variableID, uint8_t value)
{
	return AgiInterpreter::variables[variableID] == value;
}

bool sage::agi::TestCommands::equalv(uint8_t variable1ID, uint8_t variable2ID)
{
	return AgiInterpreter::variables[variable1ID] == AgiInterpreter::variables[variable2ID];
}

bool sage::agi::TestCommands::lessn(uint8_t variableID, uint8_t number)
{
	return AgiInterpreter::variables[variableID] < number;
}

bool sage::agi::TestCommands::lessv(uint8_t variable1ID, uint8_t variable2ID)
{
	return AgiInterpreter::variables[variable1ID] < AgiInterpreter::variables[variable2ID];
}

bool sage::agi::TestCommands::greatern(uint8_t variableID, uint8_t number)
{
	return AgiInterpreter::variables[variableID] > number;
}

bool sage::agi::TestCommands::greaterv(uint8_t variable1ID, uint8_t variable2ID)
{
	return AgiInterpreter::variables[variable1ID] > AgiInterpreter::variables[variable2ID];
}

bool sage::agi::TestCommands::isset(uint8_t flagID)
{
	return AgiInterpreter::flags[flagID] == 1;
}

bool sage::agi::TestCommands::issetv(uint8_t variableID)
{
	uint8_t variableValue = AgiInterpreter::variables[variableID];
	return AgiInterpreter::flags[variableValue] == 1;
}
