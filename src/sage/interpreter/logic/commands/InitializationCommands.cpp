#include "InitializationCommands.h"

void InitializationCommands::setgameid(uint8_t arg1)
{
	if (AgiInterpreter::currentLogic != nullptr)
	{
		AgiInterpreter::gameID = AgiInterpreter::currentLogic->GetMessage(arg1);
	}
}
