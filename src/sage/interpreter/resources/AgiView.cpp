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
		ViewLoop viewLoop;// { LoopId = loopIndex };
		//ViewLoops.Add(viewLoop);

		for (uint8_t celIndex = 0; celIndex < celsInLoopCount[loopIndex]; celIndex++)
		{
			uint8_t offset = 0;
			uint8_t celPosition = this->loopLocations[loopIndex] + this->celLocations[loopIndex][celIndex];
			uint8_t width = file.data[celPosition] * 2;
			uint8_t height = file.data[celPosition + ++offset];

			// This byte has the following format:
			// Bit	What it does
			//	0	Transparency Color
			//	1	Bit indicating if mirroring is enabled
			//	2-4	Loop indice that is not mirrored
			//	
			BitSetHelper<8> bitset(file.data[celPosition + ++offset]);
			/*std::bitset<8> bits(file.data[celPosition + ++offset]);
			const std::bitset<8> mask("00001111");*/
			uint64_t transparentColor = bitset.get_range_ulong(4, 7); //(bits & mask).to_ulong();

			// this mirroring appears correct but needs to be better tested
			//bool isMirrored = bits[7] == 1 && (bits & std::bitset<8>("00001110")).to_ulong() != loopIndex;
			//uint8_t mirroredLoopId = (bits & std::bitset<8>("00001110")).to_ulong();
			//var pixelData = Enumerable.Repeat((uint)transparentColor, width * height).ToArray();

			//for (var celDataIndex = 0; celDataIndex < height; celDataIndex++)
			{
				/*var x = 0;
				byte chunk = 0;
*/
				/*while ((chunk = file.Data[celPosition + ++offset]) != 0)
				{
					var bitArray = new BitArray(new[] { chunk });
					var pixelCount = bitArray.ConvertBitArrayToByte(0, 3);
					var pixelColor = bitArray.ConvertBitArrayToByte(4, 7);
					if (!isMirrored)
					{
						for (var originalCelx = x; x < originalCelx + pixelCount * 2; x += 2)
						{
							pixelData[(celDataIndex * width) + x] = pixelColor;
							pixelData[(celDataIndex * width) + x + 1] = pixelColor;
						}
					}
					else
					{
						for (var originalCelx = x; x < originalCelx + pixelCount * 2; x += 2)
						{
							pixelData[(celDataIndex * width) + width - x - 1] = pixelColor;
							pixelData[(celDataIndex * width) + width - x - 2] = pixelColor;
						}
					}
				}*/
			}

	//		viewLoop.Cels.Add(new ViewCell()
	//		{
	//			Color = agiColors.First(c = > c.ColorId == transparentColor),
	//			Width = width,
	//			Height = height,
	//			IsMirrored = isMirrored,
	//			Data = pixelData,
	//			MirroredLoopId = mirroredLoopId
	//		});
		}
	}
}

AgiView::AgiView(AgiFile file)
{
	LoadViewHeader(file);
	ReadLoopHeaders(file);
	ReadCelHeader(file);
}
