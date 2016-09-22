#pragma once

#include <cinttypes>

#include "../../AgiInterpreter.h"
#include "../LogicProcessor.h"

namespace sage
{
	namespace agi
	{
		class SubroutingCommands
		{
		public:
			static void call(uint8_t resourceID);
			static void call_v(uint8_t variableID);
			// return - this is handled in the logic processor
			// jump
			static void	set_scan_start();
			static void reset_scan_start();
		};
	}
}