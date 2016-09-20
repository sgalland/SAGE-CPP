#include "AgiVersion.h"

std::string sage::agi::AgiVersion::GetVersion()
{
	std::string version;
	std::string versionBuffer(8, '0');
	bool isVersionFound = false;
	const std::string searchString = "Version ";
	const std::string fileName = "AGIDATA.OVL";

	fs::path path = { fs::current_path() / fileName };
	fs::ifstream agiData{ path, fs::ifstream::binary };

	if (agiData.is_open())
	{
		uintmax_t fileLength = fs::file_size(path);

		while (agiData.tellg() < fileLength)
		{
			char b = agiData.get();

			if (isVersionFound)
			{
				char c = static_cast<char>(b);
				if (c == '\0')
					break;
				version += c;
			}
			else
			{
				versionBuffer = versionBuffer.substr(1) + static_cast<char>(b);

				if (versionBuffer.find(searchString) != std::string::npos)
				{
					isVersionFound = true;
				}
			}
		}
	}

	return version;
}
