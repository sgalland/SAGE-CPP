#pragma once

#include <cinttypes>
#include <string>
#include <vector>

namespace sage
{
	namespace agi
	{

		class AgiStringHelper
		{
		public:
			static std::string GetString(uint8_t source[], int position)
			{
				uint8_t b;
				std::vector<uint8_t> byteString;
				int loopIterator = 0;

				do
				{
					b = source[position + loopIterator++];
					byteString.push_back(b);
				} while (b != 0x00);

				return std::string(byteString.begin(), byteString.end() - 1); // return everything but the null terminator
			}
		};

	}
}