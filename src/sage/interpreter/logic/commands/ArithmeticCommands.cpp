#include "ArithmeticCommands.h"

void ArithmeticCommands::increment(uint8_t variableID)
{
	AgiInterpreter::variables[variableID]++;
}

void ArithmeticCommands::decrement(uint8_t variableID)
{
	AgiInterpreter::variables[variableID]--;
}

void ArithmeticCommands::assign(uint8_t variableID, uint8_t number)
{
	AgiInterpreter::variables[variableID] = number;
}

void ArithmeticCommands::assignv(uint8_t variableID1, uint8_t variableID2)
{
	AgiInterpreter::variables[variableID1] = AgiInterpreter::variables[variableID2];
}

void ArithmeticCommands::addn(uint8_t variableID, uint8_t number)
{
	AgiInterpreter::variables[variableID] += number;
}

void ArithmeticCommands::addv(uint8_t variableID1, uint8_t variableID2)
{
	AgiInterpreter::variables[variableID1] += AgiInterpreter::variables[variableID2];
}

void ArithmeticCommands::subn(uint8_t variableID, uint8_t number)
{
	AgiInterpreter::variables[variableID] -= number;
}

void ArithmeticCommands::subv(uint8_t variableID1, uint8_t variableID2)
{
	AgiInterpreter::variables[variableID1] -= AgiInterpreter::variables[variableID2];
}
