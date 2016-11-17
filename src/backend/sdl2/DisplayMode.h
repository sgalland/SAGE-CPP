#pragma once

class DisplayMode
{
	friend class Graphics;
protected:
	int width;
	int height;
	int refreshRate;

	DisplayMode(int width, int height, int refreshRate);
public:
	int getWidth();
	int getHeight();
	int getRefreshRate();
};