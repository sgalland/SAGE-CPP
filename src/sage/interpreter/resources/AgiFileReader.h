#pragma once

#include <cinttypes>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

const int EMPTY_DIRECTORY = 0xFFFFF;
const int VALID_SIGNATURE = 0x3412;

enum class AgiFileType
{
	Logic,
	Picture,
	Sound,
	View
};

// A directory entry for a resource listed in a VOL file.
// The vol file lists a max of 256 entries for a given resource type.
struct AgiDirectoryEntry
{
	uint16_t signature;
	uint8_t volNumber;
	uint32_t dataOffset;
	uint8_t resourceId;
};

struct AgiFile
{
	int16_t resourceId;
	uint8_t volNumber;
	int16_t fileSize;
	std::vector<uint8_t> data;
};



class AgiFileReader
{
private:
	std::vector<AgiDirectoryEntry> directoryEntries;
	AgiFileType fileType;

	void LoadDirectoryEntries(AgiFileType fileType);
	std::string GetAgiFileName();
	std::string GetAgiFileFullName();
public:
	AgiFileReader();
	AgiFileReader(AgiFileType fileType);
	~AgiFileReader();

	std::vector<AgiDirectoryEntry> GetDirectoryEntries();
	AgiFile GetFile(uint8_t resourceId);

	void ExtractFile(uint8_t resourceId, fs::path filePath);
};

