#include "Texture.h"
#include "Graphics.h"

Texture::Texture(int width, int height) :Texture(width, height, AgiColor::getColorByDosColor(0))
{
}

Texture::Texture(int width, int height, AgiColor transparentColor) : Texture(0, 0, width, height, true, transparentColor)
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height) : Texture(xPosition, yPosition, width, height, false, AgiColor::getColorByDosColor(0))
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height, AgiColor transparentColor) : Texture(xPosition, yPosition, width, height, true, transparentColor)
{
}

Texture::Texture(int xPosition, int yPosition, int width, int height, bool transparent, AgiColor transparentColor)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->width = width;
	this->height = height;
	this->transparent = transparent;
	this->transparentColor = transparentColor;

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
	memcpy(this->surface->pixels, &this->pixelBuffer[0], this->surface->pitch * this->surface->h);

	if (this->transparent)
	{
		if (SDL_SetColorKey(this->surface, SDL_TRUE, SDL_MapRGB(this->surface->format, transparentColor.r, transparentColor.g, transparentColor.b)) != 0)
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

void Texture::initialize()
{
	this->width = width;
	this->height = height;
	this->texture = nullptr;
	this->pixelBuffer.resize(width * height);

	if ((this->surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	if ((this->texture = SDL_CreateTexture(Graphics::renderer, this->surface->format->format, SDL_TEXTUREACCESS_STREAMING, this->width, this->height)) == nullptr)
	{
		std::cout << "SDL Error:\n\t" << SDL_GetError() << std::endl;
		exit(1);
	}

	SDL_SetSurfaceRLE(this->surface, SDL_TRUE);
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

void Texture::setTransparentColor(AgiColor transparentColor)
{
	this->transparent = true;
	this->transparentColor = transparentColor;
}

AgiColor Texture::getTransparentColor()
{
	return this->transparentColor;
}

void Texture::setData(std::vector<uint32_t> data)
{
	this->pixelBuffer.clear();

	// Convert the pixel color from DOS to RGB.
	for (int index = 0; index < data.size(); index++)
	{
		AgiColor color = AgiColor::getColorByDosColor(data.at(index));
		uint32_t convColor = SDL_MapRGB(this->surface->format, color.r, color.g, color.b);
		this->pixelBuffer.push_back(convColor);
	}

	UpdateTexture();
}
