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

void sage::agi::ObjectControlCommands::set_cel(uint8_t objectID, uint8_t celID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	ViewCell *cel = &entry->startOfData->getViewLoops().at(entry->currentLoop).cels().at(celID);
	entry->currentCel = celID;
	entry->pointerToStartOfCelData = cel;
	entry->xSize = cel->getWidth();
	entry->ySize = cel->getHeight();
}

void sage::agi::ObjectControlCommands::set_cel_v(uint8_t objectID, uint8_t variableID)
{
	uint8_t celID = AgiInterpreter::variables[variableID];
	set_cel(objectID, celID);
}

void sage::agi::ObjectControlCommands::last_cel(uint8_t objectID, uint8_t variableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	AgiInterpreter::variables[variableID] = entry->startOfData->getViewLoops().at(entry->currentLoop).cels().size() - 1;
}

void sage::agi::ObjectControlCommands::current_cel(uint8_t objectID, uint8_t variableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	AgiInterpreter::variables[variableID] = entry->currentCel;
}

void sage::agi::ObjectControlCommands::current_loop(uint8_t objectID, uint8_t variableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	AgiInterpreter::variables[variableID] = entry->currentLoop;
}

void sage::agi::ObjectControlCommands::current_view(uint8_t objectID, uint8_t variableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	AgiInterpreter::variables[variableID] = entry->currentView;
}

void sage::agi::ObjectControlCommands::set_priority(uint8_t objectID, uint8_t number)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->priority = number;
		entry->flags |= ViewFlags::FixedPriority;
	}

}

void sage::agi::ObjectControlCommands::set_priority_v(uint8_t objectID, uint8_t variable)
{
	set_priority(objectID, AgiInterpreter::variables[variable]);
}

void sage::agi::ObjectControlCommands::release_priority(uint8_t objectID)
{
	// I am pretty sure this is correct but needs to be verified
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags &= ~ViewFlags::FixedPriority;
	}
}

void sage::agi::ObjectControlCommands::get_priority(uint8_t objectID, uint8_t variableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr) 
	{
		AgiInterpreter::variables[variableID] = entry->priority;
	}
}

void sage::agi::ObjectControlCommands::position(uint8_t objectID, uint8_t x, uint8_t y)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr) 
	{
		entry->x = x;
		entry->y = y;
	}
}

void sage::agi::ObjectControlCommands::position_v(uint8_t objectID, uint8_t xVariableID, uint8_t yVariableID)
{
	position(objectID, AgiInterpreter::variables[xVariableID], AgiInterpreter::variables[yVariableID]);
}

void sage::agi::ObjectControlCommands::draw(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		//entry->flags &= ViewFlags::Updating
		set_cel(objectID, entry->currentCel);
	}
}

void sage::agi::ObjectControlCommands::erase(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags = ~ViewFlags::Update; // We might need another flag for this.
	}
}

void sage::agi::ObjectControlCommands::get_posn(uint8_t objectID, uint8_t xVariableID, uint8_t yVariableID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		AgiInterpreter::variables[xVariableID] = entry->x;
		AgiInterpreter::variables[yVariableID] = entry->y;
	}
}

void sage::agi::ObjectControlCommands::start_cycling(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags &= ViewFlags::Cycling;
	}
}

void sage::agi::ObjectControlCommands::stop_cycling(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags &= ~ViewFlags::Cycling;
	}
}

void sage::agi::ObjectControlCommands::normal_cycling(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags &= ~ViewFlags::ReverseCycling;
	}
}

void sage::agi::ObjectControlCommands::reverse_cycle(uint8_t objectID)
{
	ViewTableEntry *entry = AgiInterpreter::viewTable[objectID];
	if (entry != nullptr)
	{
		entry->flags &= ViewFlags::ReverseCycling;
	}
}
