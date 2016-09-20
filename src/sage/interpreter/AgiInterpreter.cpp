#include "AgiInterpreter.h"


uint8_t AgiInterpreter::variables[256];
uint8_t AgiInterpreter::flags[256];
std::string AgiInterpreter::strings[12];
std::string AgiInterpreter::gameID;
AgiLogic* AgiInterpreter::currentLogic;
AgiLogic* AgiInterpreter::logics[256];

sage::agi::AgiInterpreter::AgiInterpreter()
{
}


sage::agi::AgiInterpreter::~AgiInterpreter()
{
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
