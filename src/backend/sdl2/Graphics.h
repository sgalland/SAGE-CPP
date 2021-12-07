#pragma once

#include "DisplayMode.h"
#include "Texture.h"
#include "../../sage/interpreter/helpers/AgiColor.h"

#ifdef linux
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

class Graphics
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Palette* palette;
	std::vector<Texture*> batchList;
	bool isFullscreen;
public:
	Graphics(int width, int height);
	~Graphics();
	void push(Texture* texture);

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



	SDL_Renderer* getSDLRenderer();
};