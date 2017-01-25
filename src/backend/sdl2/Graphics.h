#pragma once

#include "DisplayMode.h"
#include "Texture.h"
#include "../../sage/interpreter/helpers/AgiColor.h"

#include <iostream>

#ifdef linux
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

class Graphics
{
	friend class Texture;
	friend class MenuBar;
	friend class BitmapFont;
private:
	static SDL_Window *window;
	static SDL_Renderer *renderer;
	static SDL_Palette *palette;
	std::vector<Texture*> batchList;
	bool isFullscreen;
public:
	Graphics(int width, int height);
	~Graphics();
	void push(Texture * texture);

	// Inherited via BaseGraphics
	void initialize(int width, int height);
	void quit();
	void clear();
	void clear(int r, int g, int b);
	void render();
	void fullscreen();
	void windowed();
	bool getIsFullscreen();
	void setWindowTitle(std::string windowTitle);
	std::vector<DisplayMode> getDisplayModes();
	void setWindowSize(int width, int height);
	void setScale(int scale);
	void recreateRenderer();
};