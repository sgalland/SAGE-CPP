#include "ViewCell.h"

ViewCell::ViewCell(AgiColor color, uint8_t width, uint8_t height, bool mirrored, std::vector<uint32_t> data, uint8_t mirroredLoopID)
{
	this->transparentColor = color;
	this->width = width;
	this->height = height;
	this->mirrored = mirrored;
	this->data = data;
	this->mirroredLoopID = mirroredLoopID;
}

//ViewCell::ViewCell(AgiColor color, uint8_t width, uint8_t height, bool mirrored, uint8_t ** data, uint8_t mirroredLoopID)
//{
//	this->color = color;
//	this->width = width;
//	this->height = height;
//	this->mirrored = mirrored;
//	//this->data = data;
//	this->mirroredLoopID = mirroredLoopID;
//}

ViewCell::~ViewCell()
{
	/*if (this->data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}*/
}

uint8_t ViewCell::getWidth()
{
	return this->width;
}

uint8_t ViewCell::getHeight()
{
	return this->height;
}

//std::vector<uint32_t> ViewCell::getData()
//{
//	return this->data;
//}

AgiColor ViewCell::getColor()
{
	return this->transparentColor;
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

void ViewCell::setColor(AgiColor color)
{
	this->transparentColor = color;
}

void ViewCell::setMirrored(bool mirrored)
{
	this->mirrored = mirrored;
}

void ViewCell::setMirroredLoopID(uint8_t mirroredLoopID)
{
	this->mirroredLoopID = mirroredLoopID;
}

AgiColor ViewCell::getTransparentColor()
{
	return this->transparentColor;
}
