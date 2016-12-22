#pragma once

#include <string>
#include <vector>

#include "resources/AgiLogic.h"
#include "resources/AgiView.h"
#include "resources/Views/ViewTableEntry.h"
#include "resources/AgiPicture.h"
#include "logic/LogicProcessor.h"
#include "AgiVersion.h"

using namespace sage::agi;

namespace sage
{
	namespace agi
	{
		//class LogicProcessor;

		class AgiInterpreter
		{
			friend class ResourceCommands;
			friend class SubroutineCommands;
			friend class ProgramControlCommands;
			friend class ObjectMotionControlCommands;
		private:
			const static int MAX_RESOURCES = 256;
			const static int MAX_STRINGS = 12;
			static AgiLogic* logics[MAX_RESOURCES];
			static AgiView* views[MAX_RESOURCES];
			static AgiPicture* pictures[MAX_RESOURCES];
			static ViewTableEntry* viewTable[MAX_RESOURCES];
		public:
			static uint8_t variables[256];
			static uint8_t flags[256];
			static std::string strings[12];
			static std::string gameID; // this is probably the wrong place for this...
			static AgiLogic* currentLogic;
			static LogicProcessor logicProcessor;

			AgiInterpreter();
			~AgiInterpreter();

			static std::string ReadGameID();

			//bool ConfirmInterpreterVersion()
			//{
			//	std::string version = AgiVersion::GetVersion();
			//}

			void Execute();
		};

	}
}