#pragma once

#include <cinttypes>
#include <vector>

#include "../../helpers/AgiColor.h"

class ViewCell
{
protected:
	uint8_t width;
	uint8_t height;
	AgiColor transparentColor;
	bool mirrored;
	std::vector<uint32_t> data;
	uint8_t mirroredLoopID;
public:
	ViewCell(AgiColor color, uint8_t width, uint8_t height, bool mirrored, std::vector<uint32_t> data, uint8_t mirroredLoopID);
	~ViewCell();

	uint8_t getWidth();
	uint8_t getHeight();
	AgiColor getColor();
	std::vector<uint32_t> getData();
	bool getMirrored();
	uint8_t getMirroredLoopID();

	void setWidth(uint8_t width);
	void setHeight(uint8_t height);
	void setData(std::vector<uint32_t> data);
	void setColor(AgiColor color);
	void setMirrored(bool mirrored);
	void setMirroredLoopID(uint8_t mirroredLoopID);
	AgiColor getTransparentColor();
};