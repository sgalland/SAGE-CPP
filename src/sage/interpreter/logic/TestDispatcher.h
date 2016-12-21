#pragma once

#include "DispatcherBase.h"

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