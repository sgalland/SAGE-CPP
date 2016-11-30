#pragma once

#include <SDL.h>
#include <vector>

class Texture
{
	friend class Graphics;
protected:
	int32_t width;
	int32_t height;
	int32_t xPosition;
	int32_t yPosition;

	std::vector<uint8_t> pixelBuffer;
	SDL_Texture *texture;
	SDL_Surface *surface;
public:
	Texture(int width, int height);
	Texture(int xPosition, int yPosition, int width, int height);
	~Texture();
	uint8_t & operator[](int index);
	// temp hack for testing, this probably doesn't need to be in the final version
	Uint32 getPixelFormat();
	void UpdateTexture();

	// Inherited via BaseTexture
	 void initialize();
	 void quit();
	 int32_t getWidth();
	 int32_t getHeight();
	 int32_t getXPosition();
	 int32_t getYPosition();

	 std::vector<uint8_t> getData();

	 void setData(std::vector<uint8_t> data);
};