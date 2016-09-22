#include "AgiLogic.h"



sage::agi::AgiLogic::AgiLogic(AgiFile file, uint8_t resourceID) 
	: Resource(file, resourceID)
{
	ExtractLogicCode();
	LoadMessages();
}


sage::agi::AgiLogic::~AgiLogic()
{
}

std::string sage::agi::AgiLogic::GetMessage(int messageIndex)
{
	return this->messages.at(messageIndex);
}

std::vector<std::string> sage::agi::AgiLogic::GetMessages()
{
	return this->messages;
}

std::vector<uint8_t> sage::agi::AgiLogic::GetLogicData()
{
	return this->logicData;
}


void sage::agi::AgiLogic::ExtractLogicCode()
{
	if (file.data.size() > 0)
	{
		int codeSize = file.data[0] + (file.data[1] << 8);
		if (codeSize > 1) // why is this 1???
		{
			logicData.resize(codeSize);
			std::copy(file.data.begin() + 2, file.data.begin() + codeSize, logicData.begin());
		}
	}
}


void sage::agi::AgiLogic::LoadMessages()
{
	int messageSectionStart = file.data[0] + (file.data[1] << 8) + 2;
	int messageSectionEndPosition = file.data[messageSectionStart + 1] + (file.data[messageSectionStart + 2] << 8);
	int messageCount = file.data[messageSectionStart];
	messageSectionStart += 3; // The messages start after the message section header

	// Decrypt the message section
	int messageHeaderLength = messageCount * 2; // message indexes are two bytes each
	int dataPositionStart = messageSectionStart + messageHeaderLength;
	int dataPositionEnd = messageSectionStart + messageSectionEndPosition - 2;
	AgiEncryption::DecryptArray(&file.data[0], dataPositionStart, dataPositionEnd);

	messages.resize(messageCount);
	for (int message = 0; message < messageCount; message++)
	{
		int messageIndex = file.data[messageSectionStart + message * 2] +
			(file.data[messageSectionStart + message * 2 + 1] << 8) - 2;
		int i = 0;
		if (messageIndex > 0)
		{
			messages[message] = AgiStringHelper::GetString(&file.data[0], messageSectionStart + messageIndex);
		}
	}
}
