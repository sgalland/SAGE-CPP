#include "ResourceCommands.h"

void sage::agi::ResourceCommands::load_resource(uint8_t resourceID)
{
	if (AgiInterpreter::logics[resourceID] != nullptr)
		delete AgiInterpreter::logics[resourceID]; // theoretically we should never run into this...

	AgiFileReader reader(AgiFileType::Logic);
	AgiInterpreter::logics[resourceID] = new AgiLogic(reader.GetFile(resourceID), resourceID);
}

void sage::agi::ResourceCommands::load_logic(uint8_t resourceID)
{
	load_resource(resourceID);
}

void sage::agi::ResourceCommands::load_logic_v(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	load_resource(resourceID);
}
