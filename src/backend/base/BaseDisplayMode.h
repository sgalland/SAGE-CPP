#pragma once

class BaseDisplayMode
{
	friend class BaseGraphics;
protected:
	int width;
	int height;
	int refreshRate;
public:
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual int getRefreshRate() = 0;
};