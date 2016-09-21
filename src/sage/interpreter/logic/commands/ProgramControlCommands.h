#pragma once

#include <cinttypes>

#include "../../AgiInterpreter.h"

class ProgramControlCommands
{
public:
	static void new_room(uint8_t roomiD);
	static void new_room_v(uint8_t variableID);
};