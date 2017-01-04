#pragma once

#include "AgiColor.h"
#include "../../../backend/sdl2/Texture.h"

class AgiColorConverter
{
public:
	static inline uint32_t toUint32(Texture &texture, AgiColor &color)
	{
		uint32_t wtf = SDL_MapRGB(texture.getSDLSurface()->format, color.r, color.g, color.b);
		return SDL_MapRGB(texture.getSDLSurface()->format, color.r, color.g, color.b);
	}

	static inline std::vector<uint32_t> convertVectorDosColorToVectorUint32(Texture &texture, std::vector<uint32_t> &pixels)
	{
		std::vector<uint32_t> retPixels;
		for (int i = 0; i < pixels.size(); i++)
		{
			AgiColor color = AgiColor::getColorByDosColor(pixels[i]);
			retPixels.push_back(SDL_MapRGB(texture.getSDLSurface()->format, color.r, color.g, color.b));
		}

		return retPixels;
	}
};