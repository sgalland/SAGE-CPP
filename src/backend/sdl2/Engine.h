#pragma once

#include "Graphics.h"

class Engine
{
public:
	Engine(int width, int height);
	~Engine();

	Graphics *graphics;

	void initialize();
	void quit();
};
