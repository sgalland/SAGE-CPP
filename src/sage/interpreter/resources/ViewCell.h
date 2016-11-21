#pragma once

#include <cinttypes>
#include <vector>

class ViewCell
{
protected:
	uint8_t width;
	uint8_t height;
	//AgiColor color;
	bool mirrored;
	std::vector<uint32_t> data; // NOTE: does this need to be 32 bit??
	uint8_t mirroredLoopID;
public:
	ViewCell(uint8_t width, uint8_t height, bool mirrored, std::vector<uint32_t> data, uint8_t mirroredLoopID);

	uint8_t getWidth();
	uint8_t getHeight();
	std::vector<uint32_t> getData();
	bool getMirrored();
	uint8_t getMirroredLoopID();

	void setWidth(uint8_t width);
	void setHeight(uint8_t height);
	void setData(std::vector<uint32_t> data);
	void setMirrored(bool mirrored);
	void setMirroredLoopID(uint8_t mirroredLoopID);
};