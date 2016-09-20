#pragma once

#include "DispatcherBase.h"
#include "DispatcherContainer.h"
#include "commands\InitializationCommands.h"

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