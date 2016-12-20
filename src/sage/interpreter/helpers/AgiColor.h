#pragma once

#include <string>
#include <vector>
#include <SDL.h>

class AgiColor
{
	friend class Graphics;
	friend class Texture;
protected:
	static std::vector<AgiColor> colors;
	std::string name;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	//uint32_t rgb;
	uint8_t dosColor;
	
	//uint32_t CreateRGBValue();
public:
	AgiColor();
	AgiColor(uint8_t dosColor, std::string name, uint8_t r, uint8_t g, uint8_t b);

	//uint32_t getRGBValue();

	static const AgiColor getColorByDosColor(int dosColor);
};

