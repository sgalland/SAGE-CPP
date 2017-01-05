#include "ObjectControlCommands.h"
#include "../../AgiInterpreter.h"

void sage::agi::ObjectControlCommands::animate_obj(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	entry->flags = ViewFlags::Animated | ViewFlags::Update | ViewFlags::Cycling;
	entry->motion = ViewMotion::Normal;
	entry->cycle = ViewCycle::Normal;
	entry->direction = ViewDirection::Stationary;
}

void ObjectControlCommands::unanimate_all()
{
	// all objects are removed from the control list and considered non-existant
	// ---- Does this mean that everything is deleted from the view table or is animation stopped? -- Sean

	for (auto viewObject : AgiInterpreter::viewTable)
	{
		/*if (viewObject != nullptr)
		{
		delete viewObject;
		viewObject = nullptr;
		}*/
		viewObject->flags &= ~ViewFlags::Animated;
	}
}

void sage::agi::ObjectControlCommands::set_view(uint8_t objectID, uint8_t resourceID)
{
	AgiView *view = AgiInterpreter::views[resourceID];
	AgiInterpreter::viewTable[objectID] = new ViewTableEntry(resourceID, view);

}

void sage::agi::ObjectControlCommands::set_view_v(uint8_t objectID, uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	set_view(objectID, resourceID);
}

void sage::agi::ObjectControlCommands::set_loop(uint8_t objectID, uint8_t loopID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	entry->currentLoop = loopID;
	entry->pointerToStartOfLoopData = &entry->startOfData->getViewLoops().at(loopID);
	entry->numberOfCels = entry->startOfData->getViewLoops().at(loopID).cels().size();
}

void sage::agi::ObjectControlCommands::set_loop_v(uint8_t objectID, uint8_t variableID)
{
	uint8_t resourceID = AgiInterpreter::variables[variableID];
	set_loop(objectID, resourceID);
}

void sage::agi::ObjectControlCommands::fix_loop(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	entry->flags |= ViewFlags::LoopFixed;
}

void sage::agi::ObjectControlCommands::release_loop(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	entry->flags &= ~ViewFlags::LoopFixed;
	// http://wiki.scummvm.org/index.php/AGI/Specifications/Logic#Object_control_commands
	// set the loop to the same as the direction if loops < 4 and > 1
	if (entry->numberOfLoops > 1 && entry->numberOfLoops < 4)
	{
		switch (entry->direction)
		{
		case ViewDirection::NorthEast:
		case ViewDirection::East:
		case ViewDirection::SouthEast:
			set_loop(objectID, 0);
			break;
		case ViewDirection::SouthWest:
		case ViewDirection::West:
		case ViewDirection::NorthWest:
			set_loop(objectID, 1);
			break;
		default: // retain the current loop
			break;
		}
	}
	else if (entry->numberOfLoops > 4)
	{
		switch (entry->direction)
		{
		case ViewDirection::North:
			set_loop(objectID, 3);
			break;
		case ViewDirection::NorthEast:
		case ViewDirection::East:
		case ViewDirection::SouthEast:
			set_loop(objectID, 0);
			break;
		case ViewDirection::South:
			set_loop(objectID, 2);
			break;
		case ViewDirection::SouthWest:
		case ViewDirection::West:
		case ViewDirection::NorthWest:
			set_loop(objectID, 1);
			break;
		default: // retain the current loop
			break;
		}
	}
}
