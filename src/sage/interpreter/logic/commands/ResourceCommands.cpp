#include "ResourceCommands.h"
#include "../../resources/AgiView.h"
#include "../../resources/AgiPicture.h"
#include "../../AgiInterpreter.h"

AgiFile & sage::agi::ResourceCommands::load_resource(uint8_t resourceID, AgiFileType fileType)
{
	AgiFileReader reader(fileType);
	return reader.GetFile(resourceID);
}

void sage::agi::ResourceCommands::load_logic(uint8_t resourceID)
{
	if (AgiInterpreter::logics[resourceID] != nullptr)
		delete AgiInterpreter::logics[resourceID]; // theoretically we should never run into this...

	AgiFile file = load_resource(resourceID, AgiFileType::Logic);
	AgiInterpreter::logics[resourceID] = new AgiLogic(file, resourceID);
}

void sage::agi::ResourceCommands::load_logic_v(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];

	if (AgiInterpreter::logics[resourceID] != nullptr)
		delete AgiInterpreter::logics[resourceID]; // theoretically we should never run into this...

	AgiFile file = load_resource(resourceID, AgiFileType::Logic);
	AgiInterpreter::logics[resourceID] = new AgiLogic(file, resourceID);
}

void sage::agi::ResourceCommands::load_pic(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	AgiFile file = load_resource(resourceID, AgiFileType::Logic);
	AgiInterpreter::pictures[resourceID] = new AgiPicture(file);
}

void sage::agi::ResourceCommands::load_view(uint8_t resourceID)
{
	//AgiFile file = load_resource(resourceID, AgiFileType::Logic);
	//AgiInterpreter::views[resourceID] = new AgiView(file);
}

void sage::agi::ResourceCommands::load_view_v(uint8_t variableID)
{
	//uint8_t resourceID = AgiInterpreter::variables[variableID];
	//AgiFile file = load_resource(resourceID, AgiFileType::Logic);
	//AgiInterpreter::views[resourceID] = new AgiView(file);
}

void sage::agi::ResourceCommands::load_sound(uint8_t resourceID)
{
	// implement me when we have sound
}

void sage::agi::ResourceCommands::discard_pic(uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	//if (resourceID < 256 && AgiInterpreter::pictures[resourceID] != nullptr)
	//{
	//	delete AgiInterpreter::pictures[resourceID];
	//	AgiInterpreter::pictures[resourceID] = nullptr;
	//}
}

void sage::agi::ResourceCommands::discard_view(uint8_t resourceID)
{
	//if (resourceID < 256 && AgiInterpreter::pictures[resourceID] != nullptr)
	//{
	//	delete AgiInterpreter::views[resourceID];
	//	AgiInterpreter::views[resourceID] = nullptr;
	//}
}

void sage::agi::ResourceCommands::discard_view_v(uint8_t variableID)
{
	//uint8_t resourceID = AgiInterpreter::variables[variableID];
	//if (resourceID < 256 && AgiInterpreter::pictures[resourceID] != nullptr)
	//{
	//	delete AgiInterpreter::views[resourceID];
	//	AgiInterpreter::views[resourceID] = nullptr;
	//}
}
