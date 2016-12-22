#include "ObjectMotionControlCommands.h"
#include "../../AgiInterpreter.h"
#include "../../resources/Views/ViewTableEntry.h"
#include "../../resources/Views/ViewFlags.h"

void ObjectMotionControlCommands::set_horizon(uint8_t horizon)
{
	// set the y coordinate to n
}

void ObjectMotionControlCommands::stop_update(uint8_t number)
{
	// object n is removed from the list of objects updated by the interpreter on each step. the object stays on the screen unchanged.
	ViewTableEntry* entry = AgiInterpreter::viewTable[number];
	//entry->flags ~= ViewFlags::Update;
}
