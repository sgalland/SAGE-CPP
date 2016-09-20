#pragma once

#include <cinttypes>

#include "../../AgiInterpreter.h"

class FlagCommands
{
public:
	static void set(uint8_t flagID);
	static void setv(uint8_t variableID);
	static void reset(uint8_t flagID);
	static void resetv(uint8_t variableID);
	static void toggle(uint8_t flagID);
	static void togglev(uint8_t variableID);
};