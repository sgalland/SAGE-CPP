#include "AgiEncryption.h"

const std::string sage::agi::AgiEncryption::ENCRYPTION_STRING = "Avis Durgan";

void sage::agi::AgiEncryption::DecryptArray(uint8_t source[], int startingIndex, int endingIndex)
{
	int stringPosition = 0;
	for (int i = startingIndex; i < endingIndex; i++)
	{
		source[i] ^= AgiEncryption::ENCRYPTION_STRING[stringPosition++ % AgiEncryption::ENCRYPTION_STRING.length()];
	}
}
