#pragma once

#include "Texture.h"

class BitmapFont
{
private:
	Texture *font;
public:
	BitmapFont(std::string fontPath);
	~BitmapFont();

	Texture* getCharacter(int characterValue);
};