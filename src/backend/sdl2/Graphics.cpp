#include "Graphics.h"

SDL_Renderer *Graphics::renderer = nullptr;

Graphics::Graphics(int width, int height)
{
	initialize(width, height);
}

Graphics::~Graphics()
{
}

void Graphics::initialize(int width, int height)
{
	window = nullptr;
	renderer = nullptr;

	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error initializing Video Subsystem: " << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer);

	if (window == nullptr || renderer == nullptr)
	{
		std::cout << "Error initializing Video Subsystem: " << SDL_GetError() << std::endl;
		exit(1);
	}
}

void Graphics::quit()
{
	SDL_VideoQuit();

	if (window != nullptr)
		SDL_DestroyWindow(window);

	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);
}

void Graphics::clear()
{
	clear(0x00, 0x00, 0x00, 0x00);
}

void Graphics::clear(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderClear(renderer);
}

void Graphics::render()
{
	SDL_Rect destSize = { 0 };

	/*for (auto texture : batchList)
	{
		SDL_RenderCopy(renderer, texture->texture, nullptr, &destSize);
	}*/

	//batchList.clear();

	SDL_RenderPresent(renderer);
}