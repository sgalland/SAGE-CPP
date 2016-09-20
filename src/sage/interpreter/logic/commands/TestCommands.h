#pragma once

#include <cinttypes>

#include "../../AgiInterpreter.h"

namespace sage
{
	namespace agi
	{
		class TestCommands
		{
		public:
			static bool equaln(uint8_t variableID, uint8_t number);
			static bool equalv(uint8_t variable1ID, uint8_t variable2ID);
			static bool lessn(uint8_t variableID, uint8_t number);
			static bool lessv(uint8_t variable1ID, uint8_t variable2ID);
			static bool greatern(uint8_t variableID, uint8_t number);
			static bool greaterv(uint8_t variable1ID, uint8_t variable2ID);
			static bool isset(uint8_t flagID);
			static bool issetv(uint8_t variableID);
		};
	}
}