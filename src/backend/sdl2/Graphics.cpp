#include "Graphics.h"

SDL_Renderer *Graphics::renderer = nullptr;
SDL_Window *Graphics::window = nullptr;
SDL_Palette *Graphics::palette = nullptr;

void Graphics::initializeColors()
{
	AgiColor::colors.emplace_back(0, "Black", 0x00, 0x00, 0x00);
	AgiColor::colors.emplace_back(1, "Green", 0x00, 0x00, 0x2A);
	AgiColor::colors.emplace_back(2, "Green", 0x00, 0x2A, 0x00);
	AgiColor::colors.emplace_back(3, "Cyan", 0x00, 0x2A, 0x2A);
	AgiColor::colors.emplace_back(4, "Red", 0x2A, 0x00, 0x00);
	AgiColor::colors.emplace_back(5, "Magenta", 0x2A, 0x00, 0x2A);
	AgiColor::colors.emplace_back(6, "Brown", 0x2A, 0x15, 0x00);
	AgiColor::colors.emplace_back(7, "Light Grey", 0x2A, 0x2A, 0x2A);
	AgiColor::colors.emplace_back(8, "Dark Grey", 0x15, 0x15, 0x15);
	AgiColor::colors.emplace_back(9, "Light Green", 0x15, 0x15, 0x3F);
	AgiColor::colors.emplace_back(10, "Light Green", 0x15, 0x3F, 0x15);
	AgiColor::colors.emplace_back(11, "Light Cyan", 0x15, 0x3F, 0x3F);
	AgiColor::colors.emplace_back(12, "Light Red", 0x3F, 0x15, 0x15);
	AgiColor::colors.emplace_back(13, "Light Magenta", 0x3F, 0x15, 0x3F);
	AgiColor::colors.emplace_back(14, "Yellow", 0x3F, 0x3F, 0x15);
	AgiColor::colors.emplace_back(15, "White", 0x3F, 0x3F, 0x3F);

	/*std::vector<SDL_Color> sdlColors;
	for (auto color : AgiColor::colors)
	{
		SDL_Color c = { color.r, color.g, color.b, SDL_ALPHA_OPAQUE };
		sdlColors.push_back(c);
	}

	palette = SDL_AllocPalette(sdlColors.size());
	if (SDL_SetPixelFormatPalette(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), palette) != 0)
	{
		std::cout << "SDL_SetPixelFormatPalette Error:\n\t" << SDL_GetError() << std::endl;
	}
	if (SDL_SetPaletteColors(palette, &sdlColors[0], 0, sdlColors.size()) != 0)
	{
		std::cout << "SDL_SetPaletteColors Error:\n\t" << SDL_GetError() << std::endl;
	}*/
}

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

	initializeColors();
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
