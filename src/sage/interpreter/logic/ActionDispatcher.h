#pragma once

#include "DispatcherBase.h"

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