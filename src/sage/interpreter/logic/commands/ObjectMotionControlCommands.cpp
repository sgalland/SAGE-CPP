#include "ObjectMotionControlCommands.h"
#include "../../AgiInterpreter.h"
#include "../../resources/Views/ViewTableEntry.h"
#include "../../resources/Views/ViewFlags.h"
#include "../GameControl.h"

void ObjectMotionControlCommands::set_horizon(uint8_t horizon)
{
	// set the y coordinate to n
}

void ObjectMotionControlCommands::stop_update(ViewTableEntry * entry)
{
	// object n is removed from the list of objects updated by the interpreter on each step. the object stays on the screen unchanged.
	if ((entry->flags & ViewFlags::Update) != ViewFlags::Update)
	{
		entry->flags &= ~ViewFlags::Update;
	}
}

void ObjectMotionControlCommands::start_update(ViewTableEntry * entry)
{
	if ((entry->flags & ViewFlags::Update) == ViewFlags::Update)
	{
		entry->flags |= ViewFlags::Update;
	}
}

void sage::agi::ObjectMotionControlCommands::player_control()
{
	AgiInterpreter::gameControl = GameControl::Player;
}

void sage::agi::ObjectMotionControlCommands::program_control()
{
	AgiInterpreter::gameControl = GameControl::Program;
}

void sage::agi::ObjectMotionControlCommands::block(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
	// Draws an invisible rectangular block that objects cannot cross the boundaries of (unless the view object has unblock on). Only one block can exist at a time, repeated calls clear previous blocks.
}

void sage::agi::ObjectMotionControlCommands::unblock()
{
	// clears all blocks
}
