#include "ActionDispatcher.h"

#include "DispatcherContainer.h"
#include "commands/InitializationCommands.h"
#include "commands/ArithmeticCommands.h"
#include "commands/FlagCommands.h"
#include "commands/ProgramControlCommands.h"
#include "commands/ResourceCommands.h"
#include "commands/SubroutineCommands.h"

sage::agi::ActionDispatcher::ActionDispatcher()
{
	this->InsertMethod(new DispatcherContainer(1, "increment", ArithmeticCommands::increment));
	this->InsertMethod(new DispatcherContainer(2, "decrement", ArithmeticCommands::decrement));
	this->InsertMethod(new DispatcherContainer(3, "assignn", ArithmeticCommands::assignn));
	this->InsertMethod(new DispatcherContainer(4, "assignv", ArithmeticCommands::assignv));
	this->InsertMethod(new DispatcherContainer(5, "addn", ArithmeticCommands::addn));
	this->InsertMethod(new DispatcherContainer(6, "addv", ArithmeticCommands::addv));
	this->InsertMethod(new DispatcherContainer(7, "subn", ArithmeticCommands::subn));
	this->InsertMethod(new DispatcherContainer(8, "subv", ArithmeticCommands::subv));
	this->InsertMethod(new DispatcherContainer(9, "lindirectv", ArithmeticCommands::lindirectv));
	this->InsertMethod(new DispatcherContainer(10, "rindirect", ArithmeticCommands::rindirect));
	this->InsertMethod(new DispatcherContainer(11, "lindirectn", ArithmeticCommands::lindirectn));
	this->InsertMethod(new DispatcherContainer(12, "set", FlagCommands::set));
	this->InsertMethod(new DispatcherContainer(13, "reset", FlagCommands::reset));
	this->InsertMethod(new DispatcherContainer(14, "toggle", FlagCommands::toggle));
	this->InsertMethod(new DispatcherContainer(15, "setv", FlagCommands::setv));
	this->InsertMethod(new DispatcherContainer(16, "resetv", FlagCommands::resetv));
	this->InsertMethod(new DispatcherContainer(17, "togglev", FlagCommands::togglev));
	this->InsertMethod(new DispatcherContainer(18, "new.room", ProgramControlCommands::new_room));
	this->InsertMethod(new DispatcherContainer(19, "new.room.v", ProgramControlCommands::new_room_v));
	this->InsertMethod(new DispatcherContainer(20, "load.logics", ResourceCommands::load_logic));
	this->InsertMethod(new DispatcherContainer(21, "load.logics.v", ResourceCommands::load_logic_v));
	this->InsertMethod(new DispatcherContainer(22, "call", SubroutingCommands::call));
	this->InsertMethod(new DispatcherContainer(23, "call.v", SubroutingCommands::call_v));

	this->InsertMethod(new DispatcherContainer(143, "set.game.id", InitializationCommands::set_game_id));
}