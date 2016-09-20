﻿#include "ActionDispatcher.h"

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
	
	this->InsertMethod(new DispatcherContainer(143, "set.game.id", InitializationCommands::setgameid));
}