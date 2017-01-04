#include "AgiColor.h"
#include "../../../backend/sdl2/Graphics.h"

std::vector<AgiColor> AgiColor::colors;

AgiColor::AgiColor()
{
}

AgiColor::AgiColor(uint8_t dosColor, uint8_t r, uint8_t g, uint8_t b)
{
	this->dosColor = dosColor;
	this->r = r;
	this->b = b;
	this->g = g;
}

AgiColor& AgiColor::getColorByDosColor(int dosColor)
{
	if (AgiColor::colors.empty())
	{
		AgiColor::colors.emplace_back(0, 0x00, 0x00, 0x00);
		AgiColor::colors.emplace_back(1, 0x00, 0x00, 168);
		AgiColor::colors.emplace_back(2, 0x00, 168, 0x00);
		AgiColor::colors.emplace_back(3, 0x00, 168, 168);
		AgiColor::colors.emplace_back(4, 168, 0x00, 0x00);
		AgiColor::colors.emplace_back(5, 168, 0x00, 168);
		AgiColor::colors.emplace_back(6, 168, 84, 0x00);
		AgiColor::colors.emplace_back(7, 168, 168, 168);
		AgiColor::colors.emplace_back(8, 84, 84, 84);
		AgiColor::colors.emplace_back(9, 84, 84, 252);
		AgiColor::colors.emplace_back(10, 84, 252, 84);
		AgiColor::colors.emplace_back(11, 84, 252, 252);
		AgiColor::colors.emplace_back(12, 252, 84, 84);
		AgiColor::colors.emplace_back(13, 252, 84, 252);
		AgiColor::colors.emplace_back(14, 252, 252, 84);
		AgiColor::colors.emplace_back(15, 252, 252, 252);
	}

	return AgiColor::colors[dosColor];
}
