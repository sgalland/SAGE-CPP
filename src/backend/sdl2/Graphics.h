#pragma once

#include "../base/BaseGraphics.h"
#include "Texture.h"

#include <iostream>
#include <SDL.h>

class Graphics : public BaseGraphics
{
	friend class Texture;
private:
	static SDL_Window *window;
	static SDL_Renderer *renderer;
	std::vector<Texture*> batchList;
public:
	Graphics(int width, int height);
	~Graphics();
	void push(Texture * texture);

	// Inherited via BaseGraphics
	virtual void initialize(int width, int height) override;
	virtual void quit() override;
	virtual void clear() override;
	virtual void clear(int r, int g, int b, int a) override;
	virtual void render() override;

};