#pragma once

#include "../base/BaseTexture.h"

class Texture : public BaseTexture
{
	// Inherited via BaseTexture
	virtual void initialize() override;
	virtual void quit() override;
	virtual uint32_t getWidth() override;
	virtual uint32_t getHeight() override;
	virtual uint32_t getXPosition() override;
	virtual uint32_t getYPosition() override;
};