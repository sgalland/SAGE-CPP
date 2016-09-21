#pragma once

#include "DispatcherBase.h"
#include "DispatcherContainer.h"
#include "commands\InitializationCommands.h"
#include "commands\ArithmeticCommands.h"
#include "commands\FlagCommands.h"
#include "commands\ProgramControlCommands.h"
#include "commands\ResourceCommands.h"
#include "commands\SubroutineCommands.h"

namespace sage
{
	namespace agi
	{
		class ActionDispatcher : public DispatcherBase<void>
		{
		public:
			ActionDispatcher();
		};
	}
}