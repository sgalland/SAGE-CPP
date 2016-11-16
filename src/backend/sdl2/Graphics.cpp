#include "Graphics.h"

SDL_Renderer *Graphics::renderer = nullptr;
SDL_Window *Graphics::window = nullptr;

Graphics::Graphics(int width, int height)
{
	initialize(width, height);
}

Graphics::~Graphics()
{
}

void Graphics::push(Texture * texture)
{
	this->batchList.push_back(texture);
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
	clear(0x00, 0x00, 0x00);
}

void Graphics::clear(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);
}

void Graphics::render()
{
	for (auto texture : batchList)
	{
		texture->UpdateTexture();

		SDL_Rect destSize = { texture->getXPosition(), texture->getYPosition(), texture->getWidth(), texture->getHeight() };
		SDL_RenderCopy(renderer, texture->texture, nullptr, &destSize);
	}

	batchList.clear();

	SDL_RenderPresent(renderer);
}