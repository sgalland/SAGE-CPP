#include "AgiColor.h"

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
	this->r = r;
	this->b = b;
	this->g = g;
	this->rgb = CreateRGBValue();
}

uint32_t AgiColor::CreateRGBValue()
{
	uint32_t rgb = this->r;
	rgb = (rgb << 8) + this->g;
	rgb = (rgb << 8) + this->b;

	return rgb;
}



const AgiColor AgiColor::getColorByDosColor(int dosColor)
{
	if (AgiColor::colors.empty())
	{
		AgiColor::colors.emplace_back(0, "Black", 0x00, 0x00, 0x00);
		AgiColor::colors.emplace_back(1, "Green", 0x00, 0x00, 0x2A);
		AgiColor::colors.emplace_back(2, "Green", 0x00, 0x2A, 0x00);
		AgiColor::colors.emplace_back(3, "Cyan", 0x00, 0x2A, 0x2A);
		AgiColor::colors.emplace_back(4, "Red", 0x2A, 0x00, 0x00);
		AgiColor::colors.emplace_back(5, "Magenta", 0x2A, 0x00, 0x2A);
		AgiColor::colors.emplace_back(6, "Brown", 0x2A, 0x15, 0x00);
		AgiColor::colors.emplace_back(7, "Light Grey", 0x2A, 0x2A, 0x2A);
		AgiColor::colors.emplace_back(8, "Dark Grey", 0x15, 0x15, 0x15);
		AgiColor::colors.emplace_back(9, "Light Green", 0x15, 0x15, 0x3F);
		AgiColor::colors.emplace_back(10, "Light Green", 0x15, 0x3F, 0x15);
		AgiColor::colors.emplace_back(11, "Light Cyan", 0x15, 0x3F, 0x3F);
		AgiColor::colors.emplace_back(12, "Light Red", 0x3F, 0x15, 0x15);
		AgiColor::colors.emplace_back(13, "Light Magenta", 0x3F, 0x15, 0x3F);
		AgiColor::colors.emplace_back(14, "Yellow", 0x3F, 0x3F, 0x15);
		AgiColor::colors.emplace_back(15, "White", 0x3F, 0x3F, 0x3F);
	}

	for (auto color : AgiColor::colors)
		if (color.dosColor == dosColor)
			return color;

	throw "Color code could not be located";
}
