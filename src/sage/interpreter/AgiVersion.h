#pragma once

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem; // TODO: Code should not directly rely on boost but rather a backend

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