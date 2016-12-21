#include "Graphics.h"

SDL_Renderer *Graphics::renderer = nullptr;
SDL_Window *Graphics::window = nullptr;
SDL_Palette *Graphics::palette = nullptr;

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
	isFullscreen = false;

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

	std::vector<DisplayMode> displayModes = this->getDisplayModes();
	std::vector<DisplayMode> locatedDisplayModes;
	int displayModeCount = SDL_GetNumDisplayModes(0); // get display modes of the first monitor
	for (int displayModeIndex = 0; displayModeIndex < displayModeCount; displayModeIndex++)
	{
		DisplayMode displayMode = displayModes[displayModeIndex];
		if (displayMode.width == width && displayMode.height == height)
		{
			locatedDisplayModes.push_back(displayMode);
		}
	}

	if (!locatedDisplayModes.empty())
	{
		std::vector<DisplayMode>::iterator displayMode = locatedDisplayModes.begin();
		SDL_SetWindowDisplayMode(this->window, displayMode->displayMode);
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
	SDL_SetRenderTarget(this->renderer, nullptr);
	SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);

	for (auto texture : batchList)
	{
		SDL_Rect destSize = { texture->getXPosition(), texture->getYPosition(), texture->getWidth(), texture->getHeight() };
		SDL_RenderCopy(renderer, texture->texture, nullptr, &destSize);
	}

	batchList.clear();

	SDL_RenderPresent(renderer);
}

void Graphics::fullscreen()
{
	SDL_SetWindowFullscreen(this->window, SDL_TRUE);
	isFullscreen = true;
}

void Graphics::windowed()
{
	SDL_SetWindowFullscreen(this->window, SDL_FALSE);
	isFullscreen = false;
}

bool Graphics::getIsFullscreen()
{
	return this->isFullscreen;
}

std::vector<DisplayMode> Graphics::getDisplayModes()
{
	std::vector<DisplayMode> displayModes;	
	int displayIndex = 0; // using the first display
	int displayModeCount = SDL_GetNumDisplayModes(displayIndex);

	for (int modeIndex = 0; modeIndex < displayModeCount; modeIndex++)
	{
		SDL_DisplayMode sdlMode;
		if (SDL_GetDisplayMode(displayIndex, modeIndex, &sdlMode) != 0)
		{
			throw "Unable to obtain display mode";
		}

		displayModes.push_back({ sdlMode.w, sdlMode.h, sdlMode.refresh_rate, &sdlMode });
	}

	return displayModes;
}
