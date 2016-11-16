#pragma once

#include "../base/BaseDisplayMode.h"

class DisplayMode : public BaseDisplayMode
{
	friend class Graphics;
protected:
	DisplayMode(int width, int height, int refreshRate);
public:
	
	// Inherited via BaseDisplayMode
	virtual int getWidth() override;
	virtual int getHeight() override;
	virtual int getRefreshRate() override;
};