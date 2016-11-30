#pragma once

#include <string>
#include <vector>

class AgiColor
{
	static std::vector<AgiColor> colors;
	std::string name;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t dosColor;
public:
	AgiColor();
	AgiColor(uint8_t dosColor, std::string name, uint8_t r, uint8_t g, uint8_t b);

	static const AgiColor getColorByDosColor(int dosColor);
};

