#pragma once

#include <string>
#include <vector>

class AgiColor
{
protected:
	static std::vector<AgiColor> colors;
public:
	AgiColor();
	AgiColor(uint8_t dosColor, uint8_t r, uint8_t g, uint8_t b);

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t dosColor;

	static AgiColor& getColorByDosColor(int dosColor);
};

