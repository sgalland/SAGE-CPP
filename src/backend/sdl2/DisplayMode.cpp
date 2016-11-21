#include "DisplayMode.h"

DisplayMode::DisplayMode(int width, int height, int refreshRate, SDL_DisplayMode *displayMode)
{
	this->width = width;
	this->height = height;
	this->refreshRate = refreshRate;
	this->displayMode = displayMode;
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
