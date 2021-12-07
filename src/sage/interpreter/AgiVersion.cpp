#include "AgiVersion.h"
#include "resources/AgiFileReader.h"
#include "resources/AgiLogic.h"


std::string sage::agi::AgiVersion::GetVersion()
{
	std::string version;
	std::string versionBuffer(8, '0');
	bool isVersionFound = false;
	const std::string searchString = "Version ";
	const std::string fileName = "AGIDATA.OVL";

	std::filesystem::path path = { std::filesystem::current_path() / fileName };
	std::ifstream agiData{ path, std::ifstream::binary };

	if (agiData.is_open())
	{
		uintmax_t fileLength = std::filesystem::file_size(path);

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

std::string sage::agi::AgiVersion::GetGameID()
{
	const std::vector<std::string> gameIDs = { "BC", "GR", "KQ", "KQ1", "KQ2", "KQ3", "KQ4", "LSL", "MG", "MH1", "PQ", "SQ" };
	AgiFileReader logicReader(AgiFileType::Logic);

	std::string gameID;
	// search each resource id until we find a two byte string and record it
	for (auto directoryEntry : logicReader.GetDirectoryEntries())
	{
		if (directoryEntry.dataOffset != EMPTY_DIRECTORY)
		{
			AgiFile file = logicReader.GetFile(directoryEntry.resourceId);
			AgiLogic logic(file, directoryEntry.resourceId);

			for (auto message : logic.GetMessages())
			{
				auto it = std::find(gameIDs.begin(), gameIDs.end(), message);

				if (message.length() >= 2 && message.length() <= 3 && isalpha(message[0]) && isalpha(message[1]) && it != gameIDs.end())
				{
					gameID = message;
				}
			}
		}
	}

	return gameID;
}
