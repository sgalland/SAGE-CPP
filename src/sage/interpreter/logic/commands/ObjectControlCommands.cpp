#include "ObjectControlCommands.h"
#include "../../AgiInterpreter.h"

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
