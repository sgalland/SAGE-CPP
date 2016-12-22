#include "ArithmeticCommands.h"
#include <cmath>

#include "../../AgiInterpreter.h"

void ArithmeticCommands::increment(uint8_t variableID)
{
	AgiInterpreter::variables[variableID]++;
}

void ArithmeticCommands::decrement(uint8_t variableID)
{
	AgiInterpreter::variables[variableID]--;
}

void ArithmeticCommands::assignn(uint8_t variableID, uint8_t number)
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

void ArithmeticCommands::lindirectn(uint8_t variableID, uint8_t number)
{
	uint8_t indirectVariable = AgiInterpreter::variables[variableID];
	AgiInterpreter::variables[indirectVariable] = number;
}

void ArithmeticCommands::lindirectv(uint8_t variableID1, uint8_t variableID2)
{
	uint8_t indirectVariable = AgiInterpreter::variables[variableID1];
	AgiInterpreter::variables[indirectVariable] = AgiInterpreter::variables[variableID2];
}

void ArithmeticCommands::rindirect(uint8_t variableID1, uint8_t variableID2)
{
	uint8_t indirectVariable = AgiInterpreter::variables[variableID2];
	AgiInterpreter::variables[variableID1] = AgiInterpreter::variables[indirectVariable];
}

void ArithmeticCommands::muln(uint8_t variableID, uint8_t number)
{
	AgiInterpreter::variables[variableID] *= number;
}

void ArithmeticCommands::mulv(uint8_t variableID1, uint8_t variableID2)
{
	AgiInterpreter::variables[variableID1] *= AgiInterpreter::variables[variableID2];
}

void ArithmeticCommands::divn(uint8_t variableID, uint8_t number)
{
	AgiInterpreter::variables[variableID] /= number;
}

void ArithmeticCommands::divv(uint8_t variableID1, uint8_t variableID2)
{
	AgiInterpreter::variables[variableID1] /= AgiInterpreter::variables[variableID2];
}

void ArithmeticCommands::random(uint8_t rangeStart, uint8_t rangeEnd, uint8_t variableID)
{
	AgiInterpreter::variables[variableID] = (rand() % (rangeEnd - rangeStart + 1)) + rangeStart;
}
