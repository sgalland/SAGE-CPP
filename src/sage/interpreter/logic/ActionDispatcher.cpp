#include "ActionDispatcher.h"

sage::agi::ActionDispatcher::ActionDispatcher()
{
	this->InsertMethod(new DispatcherContainer(143, "set.game.id", InitializationCommands::setgameid));
	this->InsertMethod(new DispatcherContainer(143, "set.game.id", InitializationCommands::setgameid));
}