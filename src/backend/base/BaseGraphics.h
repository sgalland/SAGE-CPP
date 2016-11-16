#pragma once

#include <vector>

#include "BaseDisplayMode.h"

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
	//virtual void addToBatch(Texture *texture) = 0;
	virtual void render() = 0;
	virtual void fullscreen() = 0;
	virtual void windowed() = 0;
	virtual bool getIsFullscreen() = 0;
	//virtual std::vector<BaseDisplayMode> getDisplayModes() = 0;
	//virtual void setGraphicsMode(int width, int height, int refreshRate) = 0;
	//virtual void setGraphicsMode(GraphicsMode displayMode) = 0;

	//Texture *createTexture(int width, int height);
	//Texture *createTexture(std::string filePath);
};