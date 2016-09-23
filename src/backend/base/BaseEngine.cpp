#include "BaseEngine.h"

#include <SDL.h>
#include <cstdlib>

BaseEngine::BaseEngine()
{
	initialize();
}

BaseEngine::~BaseEngine()
{
	quit();
}

void BaseEngine::initialize()
{
	atexit(SDL_Quit);
}

void BaseEngine::quit()
{
}
