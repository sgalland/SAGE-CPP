#include "AgiColor.h"

std::vector<AgiColor*> AgiColor::colors;

AgiColor::AgiColor()
{
}

AgiColor::AgiColor(uint8_t dosColor, std::string name, uint8_t r, uint8_t g, uint8_t b)
{
	this->dosColor = dosColor;
	this->name = name;
	this->r = r;
	this->b = b;
	this->g = g;
}

AgiColor* AgiColor::getColorByDosColor(int dosColor)
{
	if (AgiColor::colors.empty())
	{
		AgiColor::colors.push_back(new AgiColor(0, "Black", 0x00, 0x00, 0x00));
		AgiColor::colors.push_back(new AgiColor(1, "Green", 0x00, 0x00, 0x2A));
		AgiColor::colors.push_back(new AgiColor(2, "Green", 0x00, 0x2A, 0x00));
		AgiColor::colors.push_back(new AgiColor(3, "Cyan", 0x00, 0x2A, 0x2A));
		AgiColor::colors.push_back(new AgiColor(4, "Red", 0x2A, 0x00, 0x00));
		AgiColor::colors.push_back(new AgiColor(5, "Magenta", 0x2A, 0x00, 0x2A));
		AgiColor::colors.push_back(new AgiColor(6, "Brown", 0x2A, 0x15, 0x00));
		AgiColor::colors.push_back(new AgiColor(7, "Light Grey", 0x2A, 0x2A, 0x2A));
		AgiColor::colors.push_back(new AgiColor(8, "Dark Grey", 0x15, 0x15, 0x15));
		AgiColor::colors.push_back(new AgiColor(9, "Light Green", 0x15, 0x15, 0x3F));
		AgiColor::colors.push_back(new AgiColor(10, "Light Green", 0x15, 0x3F, 0x15));
		AgiColor::colors.push_back(new AgiColor(11, "Light Cyan", 0x15, 0x3F, 0x3F));
		AgiColor::colors.push_back(new AgiColor(12, "Light Red", 0x3F, 0x15, 0x15));
		AgiColor::colors.push_back(new AgiColor(13, "Light Magenta", 0x3F, 0x15, 0x3F));
		AgiColor::colors.push_back(new AgiColor(14, "Yellow", 0x3F, 0x3F, 0x15));
		AgiColor::colors.push_back(new AgiColor(15, "White", 0x3F, 0x3F, 0x3F));
	}

	for (auto color : AgiColor::colors)
		if (color->dosColor == dosColor)
			return color;

	throw "Color code could not be located";
}
