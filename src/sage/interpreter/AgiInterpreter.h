#pragma once

#include <string>
#include <vector>

#include "resources/AgiLogic.h"
#include "resources/AgiView.h"
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
		private:
			static AgiLogic* logics[256];
			static AgiView* views[256];
			static AgiPicture* pictures[256];
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