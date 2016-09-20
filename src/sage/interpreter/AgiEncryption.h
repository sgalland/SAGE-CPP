#pragma once

#include <string>

namespace sage
{
	namespace agi
	{
		class AgiEncryption
		{
		private:
			static const std::string ENCRYPTION_STRING;
		public:
			static void DecryptArray(uint8_t source[], int startingIndex, int endingIndex);
		};

	}
}