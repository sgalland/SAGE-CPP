#pragma once
#include <bitset>

template<int T>
class BitSetHelper : public std::bitset<T>
{
public:
	BitSetHelper() { }
	BitSetHelper(unsigned long long val) : std::bitset<T>(val) { }
	//BitSetHelper(std::bitset<T> &&source) : std::bitset<T>(source) { }

	inline uint64_t get_range_ulong(int startPosition, int endPosition)
	{
		std::string mask;
		for (int i = 0; i < T; i++)
		{
			if (i < startPosition || i > endPosition)
			{
				mask.insert("0");
			}
			else
			{
				mask.insert("1");
			}
		}

		return (static_cast<std::bitset<T>>(this) & std::bitset<T>(mask)).to_ulong();
	}
};
