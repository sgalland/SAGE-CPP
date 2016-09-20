#pragma once

#include <boost/any.hpp> // TODO: Remove boost reference from code and make sure it is in the backend
#include <cinttypes>

#include "../resources/AgiLogic.h"
#include "ActionDispatcher.h"
#include "TestDispatcher.h"

using namespace sage::agi;

namespace sage
{
	namespace agi
	{
		class LogicProcessor
		{
			friend class InitializationCommands;
			friend class TestCommands;
		private:
			TestDispatcher testDispatcher;
			ActionDispatcher actionDispatcher;
			int logicIndex;
			bool processActions;
			int codeBlockSize;

			void ProcessIf();
			void ProcessAction(uint8_t currentByte);
			int ReadCodeBlockSize();

			std::vector<uint8_t> GetArguments(int argumentCount);
		public:
			LogicProcessor();
			void Execute(uint8_t resourceID);

		};
	}
}