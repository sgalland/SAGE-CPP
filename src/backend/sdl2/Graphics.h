#pragma once

#include "../base/BaseGraphics.h"

#include <iostream>
#include <SDL.h>

class Graphics : public BaseGraphics
{
private:
	SDL_Window *window;
	static SDL_Renderer *renderer;
	//std::vector<Texture*> batchList;
public:
	Graphics(int width, int height);
	~Graphics();

	// Inherited via BaseGraphics
	virtual void initialize(int width, int height) override;
	virtual void quit() override;
	virtual void clear() override;
	virtual void clear(int r, int g, int b, int a) override;
	virtual void render() override;

};