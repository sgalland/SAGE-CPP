#include "AgiInterpreter.h"

uint8_t AgiInterpreter::variables[AgiInterpreter::MAX_RESOURCES];
uint8_t AgiInterpreter::flags[AgiInterpreter::MAX_RESOURCES];
std::string AgiInterpreter::strings[MAX_STRINGS];
std::string AgiInterpreter::gameID;
AgiLogic *AgiInterpreter::currentLogic;
AgiLogic *AgiInterpreter::logics[AgiInterpreter::MAX_RESOURCES];
AgiView *AgiInterpreter::views[AgiInterpreter::MAX_RESOURCES];
ViewTableEntry *AgiInterpreter::viewTable[AgiInterpreter::MAX_RESOURCES];
AgiPicture* AgiInterpreter::pictures[AgiInterpreter::MAX_RESOURCES];
LogicProcessor AgiInterpreter::logicProcessor;
GameControl AgiInterpreter::gameControl;

sage::agi::AgiInterpreter::AgiInterpreter()
{
}


sage::agi::AgiInterpreter::~AgiInterpreter()
{
	for (unsigned int index = 0; index < MAX_RESOURCES; index++)
	{
		AgiView *view = this->views[index];
		if (view != nullptr)
			delete view;

		AgiPicture *picture = this->pictures[index];
		if (picture != nullptr)
			delete picture;

		AgiLogic *logic = this->logics[index];
		if (logic != nullptr)
			delete logic;

		ViewTableEntry *entry = this->viewTable[index];
		if (entry != nullptr)
			delete entry;
	}
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
