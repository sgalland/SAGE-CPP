#pragma once
#include <bitset>

template<int T>
class BitSetHelper : public std::bitset<T>
{
public:
	BitSetHelper() { }
	BitSetHelper(unsigned long long val) : std::bitset<T>(val) { }

	inline uint8_t get_range_byte(int startPosition, int endPosition)
	{
		uint8_t mask = 1;
		uint8_t result = 0;

		for (size_t i = startPosition; i < endPosition; i++)
		{
			if (this->test(i))
				result |= mask;
			mask <<= 1;
		}

		return result;
	}
};
