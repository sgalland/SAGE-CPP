#pragma once

#include <cinttypes>

class BaseTexture
{
protected: 
	int32_t width;
	int32_t height;
	int32_t xPosition;
	int32_t yPosition;
public:
	virtual void initialize() = 0;
	virtual void quit() = 0;

	virtual int32_t getWidth() = 0;
	virtual int32_t getHeight() = 0;
	virtual int32_t getXPosition() = 0;
	virtual int32_t getYPosition() = 0;
};