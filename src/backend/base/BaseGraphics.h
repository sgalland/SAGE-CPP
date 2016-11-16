#pragma once

#include <vector>

#include "DisplayMode.h"

class BaseGraphics
{
protected:
	bool isFullscreen;
public:
	//virtual ~BaseGraphics() = 0;

	virtual void initialize(int width, int height) = 0;
	virtual void quit() = 0;

	virtual void clear() = 0;
	virtual void clear(int r, int g, int b) = 0;
	//void addToBatch(Texture *texture);
	virtual void render() = 0;
	virtual void fullscreen() = 0;
	virtual void windowed() = 0;
	virtual bool getIsFullscreen() = 0;
	virtual std::vector<DisplayMode> getDisplayModes() = 0;

	//Texture *createTexture(int width, int height);
	//Texture *createTexture(std::string filePath);
};