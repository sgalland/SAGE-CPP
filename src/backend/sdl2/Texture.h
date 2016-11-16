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
	Texture(int xPosition, int yPosition, int width, int height);
	~Texture();
	uint32_t & operator[](int index);
	// temp hack for testing, this probably doesn't need to be in the final version
	Uint32 getPixelFormat();
	void UpdateTexture();

	// Inherited via BaseTexture
	virtual void initialize() override;
	virtual void quit() override;
	virtual int32_t getWidth() override;
	virtual int32_t getHeight() override;
	virtual int32_t getXPosition() override;
	virtual int32_t getYPosition() override;
};