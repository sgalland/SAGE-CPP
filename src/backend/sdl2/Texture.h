#pragma once

#include <SDL.h>
#include <vector>
#include "../base/BaseTexture.h"

class Texture : public BaseTexture
{
	friend class Graphics;
	std::vector<uint32_t> pixelBuffer;
	SDL_Texture *texture;
	SDL_Surface *surface;
public:
	Texture(int width, int height);
	uint32_t & operator[](int index);
	// temp hack for testing, this probably doesn't need to be in the final version
	Uint32 getPixelFormat();
	void UpdateTexture();

	// Inherited via BaseTexture
	virtual void initialize() override;
	virtual void quit() override;
	virtual uint32_t getWidth() override;
	virtual uint32_t getHeight() override;
	virtual uint32_t getXPosition() override;
	virtual uint32_t getYPosition() override;
};