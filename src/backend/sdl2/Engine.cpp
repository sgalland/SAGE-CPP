#include "Engine.h"

#ifdef LINUX
#include <SDL2/SDL.h>
#endif

#include <cstdlib>

Engine::Engine(int width, int height)
{
	this->graphics = new Graphics(width, height);
}

Engine::~Engine()
{
	quit();
}

void Engine::initialize()
{
}

void Engine::quit()
{
	if (this->graphics != nullptr)
		delete this->graphics;

	SDL_Quit();
}
