#include "ActionDispatcher.h"

#include "DispatcherContainer.h"
#include "commands/InitializationCommands.h"
#include "commands/ArithmeticCommands.h"
#include "commands/FlagCommands.h"
#include "commands/ObjectControlCommands.h"
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
	//this->InsertMethod(new DispatcherContainer(19, "new.room.v", ProgramControlCommands::new_room_v));
	this->InsertMethod(new DispatcherContainer(20, "load.logics", ResourceCommands::load_logic));
	this->InsertMethod(new DispatcherContainer(21, "load.logics.v", ResourceCommands::load_logic_v));
	this->InsertMethod(new DispatcherContainer(22, "call", SubroutineCommands::call));
	this->InsertMethod(new DispatcherContainer(23, "call.v", SubroutineCommands::call_v));
	this->InsertMethod(new DispatcherContainer(24, "load.pic", ResourceCommands::load_pic));
	// draw pic 25
	// show pic 26
	this->InsertMethod(new DispatcherContainer(27, "discard.pic", ResourceCommands::discard_pic));
	// overlay pic 28
	// show pri screen 29
	this->InsertMethod(new DispatcherContainer(30, "load.view", ResourceCommands::load_view));
	this->InsertMethod(new DispatcherContainer(31, "load.view.v", ResourceCommands::load_view_v));
	this->InsertMethod(new DispatcherContainer(32, "discard.view", ResourceCommands::discard_view));
	this->InsertMethod(new DispatcherContainer(33, "animate.obj", ObjectControlCommands::animate_obj));
	this->InsertMethod(new DispatcherContainer(34, "unanimate.all", ObjectControlCommands::unanimate_all));
	//this->InsertMethod(new DispatcherContainer(35, "draw", ObjectControlCommands::unanimate_all));

	this->InsertMethod(new DispatcherContainer(41, "set.view", ObjectControlCommands::set_view));
	this->InsertMethod(new DispatcherContainer(42, "set.view.v", ObjectControlCommands::set_view_v));
	this->InsertMethod(new DispatcherContainer(43, "set.loop", ObjectControlCommands::set_loop));
	this->InsertMethod(new DispatcherContainer(44, "set.loop.v", ObjectControlCommands::set_loop_v));
	this->InsertMethod(new DispatcherContainer(45, "fix.loop", ObjectControlCommands::fix_loop));
	this->InsertMethod(new DispatcherContainer(46, "release.loop", ObjectControlCommands::release_loop));
	this->InsertMethod(new DispatcherContainer(47, "set.cel", ObjectControlCommands::set_cel));
	this->InsertMethod(new DispatcherContainer(48, "set.cel.v", ObjectControlCommands::set_cel_v));
	this->InsertMethod(new DispatcherContainer(49, "last.cel", ObjectControlCommands::last_cel));
	this->InsertMethod(new DispatcherContainer(50, "current.cel", ObjectControlCommands::current_cel));



	this->InsertMethod(new DispatcherContainer(91, "set.scan.start", SubroutineCommands::set_scan_start));
	this->InsertMethod(new DispatcherContainer(92, "reset.scan.start", SubroutineCommands::reset_scan_start));

	this->InsertMethod(new DispatcherContainer(143, "set.game.id", InitializationCommands::set_game_id));

	this->InsertMethod(new DispatcherContainer(153, "discard.view.v", ResourceCommands::discard_view_v));
}