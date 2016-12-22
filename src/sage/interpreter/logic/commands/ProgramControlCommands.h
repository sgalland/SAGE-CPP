#pragma once

#include <cinttypes>

namespace sage
{
	namespace agi
	{
		class ProgramControlCommands
		{
		private:
			static void exec_new_room(uint8_t roomID);
			static void disard_all_resources();
		public:
			static void new_room(uint8_t roomID);
			static void new_room_v(uint8_t variableID);
		};
	}
}