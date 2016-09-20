#include "TestDispatcher.h"



sage::agi::TestDispatcher::TestDispatcher()
{
	this->InsertMethod(new DispatcherContainer(1, "equaln", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(2, "equalv", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(3, "lessn", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(4, "lessv", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(5, "greatern", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(6, "greaterv", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(7, "isset", static_cast<cb2_t>(TestCommands::equaln)));
	this->InsertMethod(new DispatcherContainer(8, "issetv", static_cast<cb2_t>(TestCommands::equaln)));
}
