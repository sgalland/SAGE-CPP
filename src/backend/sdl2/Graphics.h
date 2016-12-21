#pragma once

#include "DisplayMode.h"
#include "Texture.h"
#include "../../sage/interpreter/helpers/AgiColor.h"

#include <iostream>
#include <SDL.h>

class Graphics
{
	friend class Texture;
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
	std::vector<DisplayMode> getDisplayModes();

};