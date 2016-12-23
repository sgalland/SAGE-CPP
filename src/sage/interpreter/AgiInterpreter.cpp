#include "AgiInterpreter.h"

uint8_t AgiInterpreter::variables[AgiInterpreter::MAX_RESOURCES];
uint8_t AgiInterpreter::flags[AgiInterpreter::MAX_RESOURCES];
std::string AgiInterpreter::strings[MAX_STRINGS];
std::string AgiInterpreter::gameID;
AgiLogic* AgiInterpreter::currentLogic;
AgiLogic* AgiInterpreter::logics[AgiInterpreter::MAX_RESOURCES];
AgiView* AgiInterpreter::views[AgiInterpreter::MAX_RESOURCES];
ViewTableEntry* AgiInterpreter::viewTable[AgiInterpreter::MAX_RESOURCES];
AgiPicture* AgiInterpreter::pictures[AgiInterpreter::MAX_RESOURCES];
LogicProcessor AgiInterpreter::logicProcessor;
GameControl AgiInterpreter::gameControl;

sage::agi::AgiInterpreter::AgiInterpreter()
{
}


sage::agi::AgiInterpreter::~AgiInterpreter()
{
}

std::string sage::agi::AgiInterpreter::ReadGameID()
{
	return AgiVersion::GetGameID();
}

void sage::agi::AgiInterpreter::Execute()
{
	// http://www.agidev.com/articles/agispec/agispecs-3.html#ss3.1
	// 1. Delay time
	// 2. Clear keyboard buffer
	//		Flag(2) -> 0
	//		Flag(4) -> 0
	// 3. Poll keyboard and joystick
	// ...

}
