#include "BitConverter.h"

int16_t BitConverter::ToInt16(std::vector<uint8_t> value, int startIndex)
{
	uint8_t values[2] = { value[startIndex], value[startIndex + 1] };
	return values[0] + (values[1] << 8);
}
