#pragma once

#ifdef linux
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

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