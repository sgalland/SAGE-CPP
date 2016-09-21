#pragma once

#include <cinttypes>

#include "../../AgiInterpreter.h"

namespace sage
{
	namespace agi
	{
		class InitializationCommands
		{
		public:
			//static void SetKey();
			static void set_game_id(uint8_t arg1);
			//static void ScriptSize();
			//static void TraceInfo();
			//static void TraceOn();
			//static void Log();
		};
	}
}
