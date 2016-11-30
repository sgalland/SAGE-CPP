#include "AgiView.h"
#include "../helpers/AgiStringHelper.h"
#include "../../../core/BitConverter.h"
#include "../../../core/BitSetHelper.h"

#include <bitset>
#include <iostream>

void AgiView::LoadViewHeader(AgiFile file)
{
	// Skip the first two bytes, which are unknown bytes.
	loopCount = file.data[2];
	uint16_t descriptionLocation = BitConverter::ToInt16(file.data, 3);
	if (descriptionLocation > 0)
	{
		Description = AgiStringHelper::GetString(&file.data[0], descriptionLocation);
	}

	// Read the loop header positions
	// Loop indices start 5 bytes past the start of the file and are two bytes wide
	const int offset = 5;
	for (uint8_t loopIndex = 0; loopIndex < this->loopCount; loopIndex++)
	{
		this->loopLocations[loopIndex] = BitConverter::ToInt16(file.data, offset + (loopIndex * 2));
	}
}

void AgiView::ReadLoopHeaders(AgiFile file)
{
	// Read the loop header
	for (int loopIndex = 0; loopIndex < this->loopCount; loopIndex++)
	{
		int loopLocation = loopLocations[loopIndex];
		this->celsInLoopCount[loopIndex] = file.data[loopLocation++];

		// Read the cel positions in each loop.
		for (int celIndex = 0; celIndex < celsInLoopCount[loopIndex]; celIndex++)
		{
			this->celLocations[loopIndex][celIndex] = BitConverter::ToInt16(file.data, loopLocation + (celIndex * 2));
		}
	}
}

void AgiView::ReadCelHeader(AgiFile file)
{
	for (uint8_t loopIndex = 0; loopIndex < this->loopCount; loopIndex++)
	{
		ViewLoop viewLoop(loopIndex);
		
		for (uint8_t celIndex = 0; celIndex < celsInLoopCount[loopIndex]; celIndex++)
		{
			uint16_t offset = 0;
			uint16_t celPosition = this->loopLocations[loopIndex] + this->celLocations[loopIndex][celIndex];
			uint8_t width = file.data[celPosition] * 2;
			uint8_t height = file.data[celPosition + ++offset];

			BitSetHelper<8> bitset(file.data[celPosition + ++offset]);
			uint8_t transparentColor = bitset.get_range_byte(0, 3);
			// this mirroring appears correct but needs to be better tested
			uint8_t mirroredLoopId = bitset.get_range_byte(4, 6);
			bool isMirrored = bitset[7] == 1 && mirroredLoopId != loopIndex;

			std::vector<uint8_t> pixelData(width * height, transparentColor);
			for (uint8_t celDataIndex = 0; celDataIndex < height; celDataIndex++)
			{
				uint16_t x = 0;
				uint8_t chunk = 0;

				while ((chunk = file.data[celPosition + ++offset]) != 0)
				{
					BitSetHelper<8> bitArray(chunk);
					uint8_t pixelCount = bitArray.get_range_byte(0, 3);
					uint8_t pixelColor = bitArray.get_range_byte(4, 7);
					if (!isMirrored)
					{
						for (uint16_t originalCelx = x; x < originalCelx + pixelCount * 2; x += 2)
						{
							pixelData[(celDataIndex * width) + x] = pixelColor;
							pixelData[(celDataIndex * width) + x + 1] = pixelColor;
						}
					}
					else
					{
						for (uint16_t originalCelx = x; x < originalCelx + pixelCount * 2; x += 2)
						{
							pixelData[(celDataIndex * width) + width - x - 1] = pixelColor;
							pixelData[(celDataIndex * width) + width - x - 2] = pixelColor;
						}
					}
				}
			}

			viewLoop.cels().emplace_back(AgiColor::getColorByDosColor(transparentColor), width, height, isMirrored, pixelData, mirroredLoopId);
		}

		viewLoops.push_back(viewLoop);
	}
}

AgiView::AgiView(AgiFile file)
{
	LoadViewHeader(file);
	ReadLoopHeaders(file);
	ReadCelHeader(file);
}

std::vector<ViewLoop> AgiView::getViewLoops()
{
	return this->viewLoops;
}
