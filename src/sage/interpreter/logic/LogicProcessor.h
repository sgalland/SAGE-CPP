#pragma once

#include <cinttypes>

#include "ActionDispatcher.h"
#include "commands/InitializationCommands.h"
#include "TestDispatcher.h"
#include "../AgiInterpreter.h"
#include "../../../core/BitConverter.h"

namespace sage
{
	namespace agi
	{
		class LogicProcessor
		{
			friend class SubroutineCommands;
			friend class InitializationCommands;
			friend class AgiInterpreter;
		private:
			ActionDispatcher actionDispatcher;
			TestDispatcher testDispatcher;
			int logicIndex;
			bool processActions;
			int codeBlockSize;
			AgiLogic* currentLogic;
			AgiInterpreter* interpreter;

			void ProcessIf();
			void ProcessElse();
			void ProcessAction(uint8_t currentByte);
			int ReadCodeBlockSize();

			std::vector<uint8_t> GetArguments(int argumentCount);
		public:
			LogicProcessor(AgiInterpreter* interpreter);
			void Execute(uint8_t resourceID);
		};
	}
}