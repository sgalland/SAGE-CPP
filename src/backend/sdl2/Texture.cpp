#include "Texture.h"
#include "Graphics.h"

Texture::Texture(int width, int height)
{
	this->xPosition = 0;
	this->yPosition = 0;
	this->width = width;
	this->height = height;

	initialize();
}

Texture::Texture(int xPosition, int yPosition, int width, int height)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->width = width;
	this->height = height;

	this->initialize();
}

Texture::~Texture()
{
	this->quit();
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
	SDL_RenderSetScale(Graphics::renderer, 4, 4);

	memcpy(this->surface->pixels, &this->pixelBuffer[0], this->surface->pitch * this->surface->h);

	if (this->texture != nullptr)
	{
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->texture = SDL_CreateTextureFromSurface(Graphics::renderer, this->surface);

	// NOTE: This pitch is width * bits per pixel. This is required for Windows. 
	// Apparently other platforms (that uses OpenGL) allow the pitch to be set to 0 as a default.
	//SDL_UpdateTexture(this->texture, NULL, &this->pixelBuffer[0], this->width * sizeof(uint32_t));
}

void Texture::initialize()
{
	this->width = width;
	this->height = height;
	this->texture = nullptr;

	if ((this->surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	pixelBuffer.resize(width * height);
}

void Texture::quit()
{
	if (this->texture != nullptr)
		SDL_DestroyTexture(this->texture);

	if (this->surface != nullptr)
		SDL_FreeSurface(this->surface);
}

int32_t Texture::getWidth()
{
	return this->width;
}

int32_t Texture::getHeight()
{
	return this->height;
}

int32_t Texture::getXPosition()
{
	return this->xPosition;
}

int32_t Texture::getYPosition()
{
	return this->yPosition;
}

std::vector<uint32_t> Texture::getData()
{
	return this->pixelBuffer;
}

void Texture::setData(std::vector<uint32_t> data)
{
	this->pixelBuffer = data;
}
