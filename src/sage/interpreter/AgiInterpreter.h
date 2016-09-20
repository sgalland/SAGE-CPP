#pragma once

#include <string>

#include "resources\AgiLogic.h"
#include "AgiVersion.h"

using namespace sage::agi;

namespace sage
{
	namespace agi
	{

		class AgiInterpreter
		{
		public:

			static uint8_t variables[256];
			static uint8_t flags[256];
			static std::string strings[12];
			static std::string gameID; // this is probably the wrong place for this...
			static AgiLogic* currentLogic;

			AgiInterpreter();
			~AgiInterpreter();

			//bool ConfirmInterpreterVersion()
			//{
			//	std::string version = AgiVersion::GetVersion();
			//}

			void Execute();
		};

	}
}