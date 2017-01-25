#pragma once

#ifdef linux
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

#include <vector>
#include <string>

class Texture
{
	friend class Graphics;
protected:
	int32_t xPosition;
	int32_t yPosition;
	bool transparent;
	uint32_t transparentColor;
	std::vector<uint32_t> pixelBuffer;
	SDL_Texture *texture;
	SDL_Surface *surface;

	void initialize(int width, int height);
	void initialize(std::string filePath);
	void quit();
public:
	Texture(int width, int height);
	Texture(int width, int height, uint32_t transparentColor);
	Texture(std::string texturePath);
	Texture(std::string texturePath, bool transparent, uint32_t transparentColor);
	Texture(int xPosition, int yPosition, int width, int height);
	Texture(int xPosition, int yPosition, int width, int height, uint32_t transparentColor);
	Texture(int xPosition, int yPosition, int width, int height, bool transparent, uint32_t transparentColor);
	Texture(int xPosition, int yPosition, bool transparent, std::string texturePath, uint32_t transparentColor);
	~Texture();
	uint32_t & operator[](int index);
	void updateTexture();

	
	int32_t getWidth();
	int32_t getHeight();
	int32_t getXPosition();
	int32_t getYPosition();

	std::vector<uint32_t> getData();

	void setTransparentColor(uint32_t transparentColor);
	uint32_t getTransparentColor();

	void setData(std::vector<uint32_t> data);
	SDL_Surface *getSDLSurface();
};