#pragma once

#include "DispatcherBase.h"
#include "DispatcherContainer.h"
#include "commands\InitializationCommands.h"
#include "commands\ArithmeticCommands.h"
#include "commands\FlagCommands.h"

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