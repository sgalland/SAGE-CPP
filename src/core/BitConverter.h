#pragma once

#include <cinttypes>
#include <vector>

class BitConverter
{
public:
	static int16_t ToInt16(std::vector<uint8_t> value, int startIndex);
};