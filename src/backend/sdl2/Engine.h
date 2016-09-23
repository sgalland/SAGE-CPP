#pragma once

#include "../base/BaseEngine.h"
#include "Graphics.h"

class Engine : public BaseEngine
{
public:
	Engine(int width, int height);
	~Engine();

	Graphics *graphics;

	void initialize();
	void quit();
};
