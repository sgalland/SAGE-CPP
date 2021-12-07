#pragma once

#include <filesystem>
#include <iostream>
#include <string>

namespace sage
{
	namespace agi
	{

		class AgiVersion
		{
		public:
			static std::string GetVersion();
			static std::string GetGameID();
		};

	}
}