#pragma once

#include <string>
#include <vector>

class AgiColor
{
	friend class Graphics;
	friend class Texture;
protected:
	static std::vector<AgiColor> colors;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t dosColor;
public:
	AgiColor();
	AgiColor(uint8_t dosColor, uint8_t r, uint8_t g, uint8_t b);

	uint8_t getDosColor();

	static AgiColor& getColorByDosColor(int dosColor);
};

