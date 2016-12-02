#include "AgiColor.h"
#include "../../../backend/sdl2/Graphics.h"

std::vector<AgiColor> AgiColor::colors;

uint32_t AgiColor::getRGBValue()
{
	return this->rgb;
}

AgiColor::AgiColor()
{
}

AgiColor::AgiColor(uint8_t dosColor, std::string name, uint8_t r, uint8_t g, uint8_t b)
{
	this->dosColor = dosColor;
	this->name = name;
	this->r = r<<2;
	this->b = b<<2;
	this->g = g<<2;
	//this->rgb = 
	CreateRGBValue();
}

uint32_t AgiColor::CreateRGBValue()
{
	this->rgb = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGB888), this->r, this->g, this->b);
	return this->rgb;
}

const AgiColor AgiColor::getColorByDosColor(int dosColor)
{
	for (auto color : AgiColor::colors)
	{
		if (color.dosColor == dosColor)
			return color;
	}

	throw "Color code could not be located";
}
