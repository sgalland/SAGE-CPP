#pragma once

#include <cinttypes>

namespace sage
{
	namespace agi
	{
		class SubroutineCommands
		{
		public:
			static void call(uint8_t resourceID);
			static void call_v(uint8_t variableID);
			// return - this is handled in the logic processor
			// jump
			static void	set_scan_start(int startPosition);
			static void reset_scan_start();
		};
	}
}