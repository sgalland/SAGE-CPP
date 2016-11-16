#include "DisplayMode.h"

DisplayMode::DisplayMode(int width, int height, int refreshRate)
{
	this->width = width;
	this->height = height;
	this->refreshRate = refreshRate;
}

int DisplayMode::getWidth()
{
	return this->width;
}

int DisplayMode::getHeight()
{
	return this->height;
}

int DisplayMode::getRefreshRate()
{
	return this->refreshRate;
}
