#include "Texture.h"
#include "Graphics.h"
#include <SDL2/SDL_image.h>
#include <iterator>

Texture::Texture(int width, int height) :Texture(width, height, 0)
{
}

Texture::Texture(int width, int height, uint32_t transparentColor) : Texture(0, 0, width, height, true, transparentColor)
{
}

Texture::Texture(std::string texturePath) : Texture(0, 0, true, texturePath, transparentColor)
{
}

Texture::Texture(std::string texturePath, bool transparent, uint32_t transparentColor) : Texture(0, 0, transparent, texturePath, transparentColor)
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height) : Texture(xPosition, yPosition, width, height, false, 0)
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height, uint32_t transparentColor) : Texture(xPosition, yPosition, width, height, true, transparentColor)
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height, bool transparent, uint32_t transparentColor)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->transparent = transparent;
	this->transparentColor = transparentColor;

	this->initialize(width, height);
}

Texture::Texture(int xPosition, int yPosition, bool transparent, std::string texturePath, uint32_t transparentColor)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->transparent = transparent;
	this->transparentColor = transparentColor;

	this->initialize(texturePath);
}

Texture::~Texture()
{
	this->quit();
}

uint32_t & Texture::operator[](int index)
{
	return pixelBuffer.at(index);
}

void Texture::updateTexture()
{
	memcpy(this->surface->pixels, &this->pixelBuffer[0], this->surface->pitch * this->surface->h);

	if (this->transparent)
	{
		if (SDL_SetColorKey(this->surface, SDL_TRUE, transparentColor) != 0)
		{
			std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
			exit(1);
		}
	}

	if (this->texture != nullptr)
	{
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}

	this->texture = SDL_CreateTextureFromSurface(Graphics::renderer, this->surface);
}

void Texture::initialize(int width, int height)
{
	if ((this->surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	if ((this->texture = SDL_CreateTexture(Graphics::renderer, this->surface->format->format, SDL_TEXTUREACCESS_STREAMING, this->surface->w, this->surface->h)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_SetSurfaceRLE(this->surface, SDL_TRUE);
	this->pixelBuffer.resize(width * height);
}

void Texture::initialize(std::string filePath)
{
	if ((this->surface = IMG_Load(filePath.c_str())) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	if ((this->texture = SDL_CreateTexture(Graphics::renderer, this->surface->format->format, SDL_TEXTUREACCESS_STREAMING, this->surface->w, this->surface->h)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_SetSurfaceRLE(this->surface, SDL_TRUE);
	this->pixelBuffer.resize(this->surface->w * this->surface->h);
	memcpy(&this->pixelBuffer[0], this->surface->pixels, this->surface->pitch);
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
	return this->surface->w;
}

int32_t Texture::getHeight()
{
	return this->surface->h;
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

void Texture::setTransparentColor(uint32_t transparentColor)
{
	this->transparent = true;
	this->transparentColor = transparentColor;
}

uint32_t Texture::getTransparentColor()
{
	return this->transparentColor;
}

void Texture::setData(std::vector<uint32_t> data)
{
	this->pixelBuffer.clear();
	std::copy(data.begin(), data.end(), std::back_inserter(pixelBuffer));	

	updateTexture();
}

SDL_Surface * Texture::getSDLSurface()
{
	return this->surface;
}
