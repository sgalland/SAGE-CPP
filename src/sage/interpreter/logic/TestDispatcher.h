#pragma once

#include "DispatcherBase.h"
#include "DispatcherContainer.h"
#include "commands/TestCommands.h"

namespace sage
{
	namespace agi
	{
		class TestDispatcher : public DispatcherBase<bool>
		{
		public:
			TestDispatcher();
		};
	}
}