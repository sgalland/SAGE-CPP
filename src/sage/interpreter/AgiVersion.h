#pragma once

#include <boost/filesystem.hpp>
#include <iostream>
#include <string>

namespace fs = boost::filesystem; // TODO: Code should not directly rely on boost but rather a backend

namespace sage
{
	namespace agi
	{

		class AgiVersion
		{
		public:
			static std::string GetVersion();
		};

	}
}