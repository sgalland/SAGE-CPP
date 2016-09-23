#pragma once

#include <vector>

class BaseGraphics
{
public:
	//virtual ~BaseGraphics() = 0;

	virtual void initialize(int width, int height) = 0;
	virtual void quit() = 0;

	virtual void clear() = 0;
	virtual void clear(int r, int g, int b, int a) = 0;
	//void addToBatch(Texture *texture);
	virtual void render() = 0;

	//Texture *createTexture(int width, int height);
	//Texture *createTexture(std::string filePath);
};