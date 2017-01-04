#include "BitmapFont.h"
#include <SDL_image.h>
#include "Graphics.h"

BitmapFont::BitmapFont(std::string fontPath)
{
	this->font = new Texture(fontPath.c_str());
	//this->font->setTransparentColor(SDL_MapRGB(this->font->getSDLSurface()->format, 255, 255, 255));
}

BitmapFont::~BitmapFont()
{
	//if (this->font != nullptr)
	//{
	//	delete font;
	//	font = nullptr;
	//}
}

Texture * BitmapFont::getCharacter(int characterValue)
{
	return font;
}
