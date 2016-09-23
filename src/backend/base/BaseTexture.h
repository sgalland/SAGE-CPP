#pragma once

class BaseTexture
{
public:
	virtual void initialize() = 0;
	virtual void quit() = 0;

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual int getXPosition() = 0;
	virtual int getYPosition() = 0;
};