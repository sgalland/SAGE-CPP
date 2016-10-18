#pragma once

#include <cinttypes>

class BaseTexture
{
protected: 
	uint32_t width;
	uint32_t height;
	uint32_t xPosition;
	uint32_t yPosition;
public:
	virtual void initialize() = 0;
	virtual void quit() = 0;

	virtual uint32_t getWidth() = 0;
	virtual uint32_t getHeight() = 0;
	virtual uint32_t getXPosition() = 0;
	virtual uint32_t getYPosition() = 0;
};