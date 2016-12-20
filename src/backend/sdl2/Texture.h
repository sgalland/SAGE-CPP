#pragma once

#include <SDL.h>
#include <vector>

#include "../../sage/interpreter/helpers/AgiColor.h"

class Texture
{
	friend class Graphics;
protected:
	int32_t width;
	int32_t height;
	int32_t xPosition;
	int32_t yPosition;
	bool transparent;
	AgiColor transparentColor;
	std::vector<uint32_t> pixelBuffer;
	SDL_Texture *texture;
	SDL_Surface *surface;

	void initialize();
	void quit();
public:
	Texture(int width, int height);
	Texture(int width, int height, AgiColor transparentColor);
	Texture(int xPosition, int yPosition, int width, int height);
	Texture(int xPosition, int yPosition, int width, int height, AgiColor transparentColor);
	Texture(int xPosition, int yPosition, int width, int height, bool transparent, AgiColor transparentColor);
	~Texture();
	uint32_t & operator[](int index);
	Uint32 getPixelFormat();
	void UpdateTexture();

	
	int32_t getWidth();
	int32_t getHeight();
	int32_t getXPosition();
	int32_t getYPosition();

	std::vector<uint32_t> getData();

	void setTransparentColor(AgiColor transparentColor);
	AgiColor getTransparentColor();

	void setData(std::vector<uint32_t> data);
};