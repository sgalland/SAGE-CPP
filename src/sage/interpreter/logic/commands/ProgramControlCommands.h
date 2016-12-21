#pragma once

#include <cinttypes>

class ProgramControlCommands
{
private:
	static void exec_new_room(uint8_t roomID);
public:
	static void new_room(uint8_t roomID);
	static void new_room_v(uint8_t variableID);
};