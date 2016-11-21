#pragma once

#include <SDL.h>

class DisplayMode
{
	friend class Graphics;
protected:
	int width;
	int height;
	int refreshRate;
	SDL_DisplayMode *displayMode;

	DisplayMode(int width, int height, int refreshRate, SDL_DisplayMode *displayMode);
public:
	int getWidth();
	int getHeight();
	int getRefreshRate();
};