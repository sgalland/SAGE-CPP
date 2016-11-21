#include "ViewCell.h"

ViewCell::ViewCell(uint8_t width, uint8_t height, bool mirrored, std::vector<uint32_t> data, uint8_t mirroredLoopID)
{
	this->width = width;
	this->height = height;
	this->mirrored = mirrored;
	this->data = data;
	this->mirroredLoopID = mirroredLoopID;
}

uint8_t ViewCell::getWidth()
{
	return this->width;
}

uint8_t ViewCell::getHeight()
{
	return this->height;
}

std::vector<uint32_t> ViewCell::getData()
{
	return this->data;
}

bool ViewCell::getMirrored()
{
	return this->mirrored;
}

uint8_t ViewCell::getMirroredLoopID()
{
	return this->mirroredLoopID;
}

void ViewCell::setWidth(uint8_t width)
{
	this->width = width;
}

void ViewCell::setHeight(uint8_t height)
{
	this->height = height;
}

void ViewCell::setData(std::vector<uint32_t> data)
{
	this->data = data;
}

void ViewCell::setMirrored(bool mirrored)
{
	this->mirrored = mirrored;
}

void ViewCell::setMirroredLoopID(uint8_t mirroredLoopID)
{
	this->mirroredLoopID = mirroredLoopID;
}
