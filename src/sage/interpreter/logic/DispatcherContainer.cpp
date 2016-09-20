#include "DispatcherContainer.h"


void sage::agi::DispatcherContainer::Initialize(uint8_t id, std::string functionName, cb0_t callback0, cb1_t callback1, cb2_t callback2, cb3_t callback3, cb4_t callback4, cb5_t callback5, uint8_t argumentCount)
{
	this->id = id;
	this->functionName = functionName;
	this->argCount = argumentCount;
	this->callback0 = callback0;
	this->callback1 = callback1;
	this->callback2 = callback2;
	this->callback3 = callback3;
	this->callback4 = callback4;
	this->callback5 = callback5;
}

void sage::agi::DispatcherContainer::Initialize(uint8_t id, std::string functionName, acb0_t callback0, acb1_t callback1, acb2_t callback2, acb3_t callback3, acb4_t callback4, acb5_t callback5, uint8_t argumentCount)
{
	this->id = id;
	this->functionName = functionName;
	this->argCount = argumentCount;
	this->acallback0 = callback0;
	this->acallback1 = callback1;
	this->acallback2 = callback2;
	this->acallback3 = callback3;
	this->acallback4 = callback4;
	this->acallback5 = callback5;
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb0_t callback0)
{
	Initialize(id, functionName, callback0, NULL, NULL, NULL, NULL, NULL, 0);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb1_t callback1)
{
	Initialize(id, functionName, NULL, callback1, NULL, NULL, NULL, NULL, 1);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb2_t callback2)
{
	Initialize(id, functionName, NULL, NULL, callback2, NULL, NULL, NULL, 2);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb3_t callback3)
{
	Initialize(id, functionName, NULL, NULL, NULL, callback3, NULL, NULL, 3);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb4_t callback4)
{
	Initialize(id, functionName, NULL, NULL, NULL, NULL, callback4, NULL, 4);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, cb5_t callback5)
{
	Initialize(id, functionName, NULL, NULL, NULL, NULL, NULL, callback5, 5);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb0_t callback0)
{
	Initialize(id, functionName, acallback0, NULL, NULL, NULL, NULL, NULL, 0);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb1_t callback1)
{
	Initialize(id, functionName, NULL, acallback1, NULL, NULL, NULL, NULL, 1);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb2_t callback2)
{
	Initialize(id, functionName, NULL, NULL, acallback2, NULL, NULL, NULL, 2);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb3_t callback3)
{
	Initialize(id, functionName, NULL, NULL, NULL, acallback3, NULL, NULL, 3);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb4_t callback4)
{
	Initialize(id, functionName, NULL, NULL, NULL, NULL, acallback4, NULL, 4);
}

sage::agi::DispatcherContainer::DispatcherContainer(uint8_t id, std::string functionName, acb5_t callback5)
{
	Initialize(id, functionName, NULL, NULL, NULL, NULL, NULL, acallback5, 5);
}

bool sage::agi::DispatcherContainer::CallTest(uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5)
{
	switch (argCount)
	{
	case 0: return callback0(); break;
	case 1: return callback1(arg1); break;
	case 2: return callback2(arg1, arg2); break;
	case 3: return callback3(arg1, arg2, arg3); break;
	case 4: return callback4(arg1, arg2, arg3, arg4); break;
	case 5: return callback5(arg1, arg2, arg3, arg4, arg5); break;
	}
	return false;
}

void sage::agi::DispatcherContainer::CallAction(uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5)
{
	switch (argCount)
	{
	case 0: return acallback0(); break;
	case 1: return acallback1(arg1); break;
	case 2: return acallback2(arg1, arg2); break;
	case 3: return acallback3(arg1, arg2, arg3); break;
	case 4: return acallback4(arg1, arg2, arg3, arg4); break;
	case 5: return acallback5(arg1, arg2, arg3, arg4, arg5); break;
	}
}

int sage::agi::DispatcherContainer::getID()
{
	return this->id;
}

uint8_t sage::agi::DispatcherContainer::getArgumentCount()
{
	return argCount;
}
