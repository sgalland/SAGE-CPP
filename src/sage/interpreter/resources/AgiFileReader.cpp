#include "AgiFileReader.h"



std::string AgiFileReader::GetAgiFileName()
{
	if (this->fileType == AgiFileType::Logic)
		return "LOGDIR";
	if (this->fileType == AgiFileType::Picture)
		return "PICDIR";
	if (this->fileType == AgiFileType::Sound)
		return "SNDDIR";
	if (this->fileType == AgiFileType::View)
		return "VIEWDIR";
	// blow up
	return "";
}

std::string AgiFileReader::GetAgiFileFullName()
{
	if (this->fileType == AgiFileType::Logic)
		return "LOGIC";
	if (this->fileType == AgiFileType::Picture)
		return "PICTURE";
	if (this->fileType == AgiFileType::Sound)
		return "SOUND";
	if (this->fileType == AgiFileType::View)
		return "VIEW";
	// blow up
	return "";
}

AgiFileReader::AgiFileReader()
{
}

AgiFileReader::AgiFileReader(AgiFileType fileType)
{
	LoadDirectoryEntries(fileType);
}


AgiFileReader::~AgiFileReader()
{
}

void AgiFileReader::LoadDirectoryEntries(AgiFileType fileType)
{
	this->fileType = fileType;
	const std::string fileName = GetAgiFileName();
	std::filesystem::path path{ std::filesystem::current_path() / fileName };
	std::ifstream file(path, std::ifstream::binary);

	int resourceCount = 0;

	if (file.is_open())
	{
		uintmax_t fileSize = std::filesystem::file_size(path);
		while (file.tellg() < fileSize)
		{
			uint8_t b1 = file.get();
			uint8_t b2 = file.get();
			uint8_t b3 = file.get();

			AgiDirectoryEntry data;
			data.volNumber = (b1 & 0xF0) >> 4;
			data.dataOffset =
				((b1 & 0x0F) << 16) +
				((b2 & 0xFF) << 8) +
				(b3 & 0xFF);

			if (data.dataOffset != EMPTY_DIRECTORY)
			{
				data.resourceId = resourceCount;
				directoryEntries.push_back(data);
			}

			resourceCount++;
		}
	}
}

std::vector<AgiDirectoryEntry> AgiFileReader::GetDirectoryEntries()
{
	return this->directoryEntries;
}

AgiFile AgiFileReader::GetFile(uint8_t resourceId)
{
	if (resourceId < 0 || resourceId > 255)
	{
		//TODO: blow up
	}
	else if (resourceId > directoryEntries.size())
	{
		//TODO: blow up
	}

	AgiDirectoryEntry dirEntry;
	for (auto entry : directoryEntries)
		if (entry.resourceId == resourceId)
			dirEntry = entry;

	std::string fileName = "VOL." + std::to_string(dirEntry.volNumber);
	std::filesystem::path filePath{ std::filesystem::current_path() / fileName };
	std::ifstream file(filePath, std::ifstream::binary);
	AgiFile agiFile;

	if (file.is_open())
	{
		file.seekg(dirEntry.dataOffset, std::ifstream::beg);
		file.read(reinterpret_cast<char*>(&dirEntry.signature), sizeof(int16_t));
		if (dirEntry.signature == VALID_SIGNATURE)
		{
			agiFile.resourceId = resourceId;
			agiFile.volNumber = file.get();
			uint8_t b1 = file.get();
			uint8_t b2 = file.get();
			agiFile.fileSize = b1 + (b2 << 8);

			agiFile.data.resize(agiFile.fileSize, 0);
			file.read((char*)&agiFile.data[0], agiFile.fileSize);
		}
	}

	return agiFile;
}

void AgiFileReader::ExtractFile(uint8_t resourceId, std::filesystem::path filePath)
{
	//AgiFile agiData = GetFile(resourceId);
	//boost::format formatter("%03i");
	//std::string fileName = GetAgiFileFullName() + "." + boost::str(formatter % static_cast<int>(resourceId));
	//std::filesystem::path outputPath = fs::path(filePath / fileName);
	//std::ofstream out(outputPath, std::ifstream::binary | std::ifstream::out);

	//if (!out.is_open())
	//{
	//	// blow up
	//}

	//out.write(reinterpret_cast<char*>(&agiData.data[0]), agiData.fileSize);
}
