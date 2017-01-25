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
		uint8_t r = 0;
		int idx = 0;
		for (int i = startPosition; i < this->size() && i <= endPosition; i++)
		{
			if (this->test(i))
			{
				r |= (uint8_t)(1 << idx);
			}
			idx++;
		}

		return r;
	}
};
