#include "Texture.h"
#include "Graphics.h"

Texture::Texture(int width, int height)
{
	this->width = width;
	this->height = height;

	texture = SDL_CreateTexture(Graphics::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	pixelBuffer.resize(width * height);
}

uint32_t & Texture::operator[](int index)
{
	return pixelBuffer.at(index);
}

Uint32 Texture::getPixelFormat()
{
	return SDL_GetWindowPixelFormat(Graphics::window);
}

void Texture::UpdateTexture()
{
	SDL_UpdateTexture(this->texture, NULL, &this->pixelBuffer[0], this->width * 4); // is the times 4 necessary?
}

void Texture::initialize()
{
}

void Texture::quit()
{
}

uint32_t Texture::getWidth()
{
	return this->width;
}

uint32_t Texture::getHeight()
{
	return this->height;
}

uint32_t Texture::getXPosition()
{
	return this->xPosition;
}

uint32_t Texture::getYPosition()
{
	return this->yPosition;
}
