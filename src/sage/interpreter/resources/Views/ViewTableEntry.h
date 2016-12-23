#pragma once

#include "ViewDirection.h"
#include "ViewCycle.h"
#include "ViewFlags.h"
#include "ViewMotion.h"

namespace sage
{
	namespace agi
	{
		class ViewTableEntry
		{
		public:
			//uint16_t stepTime;
			//uint16_t x;
			//uint16_t y;
			//uint8_t currentView;
			//AgiView& startOfData;
			//uint8_t currentLoop;
			//uint8_t numberOfLoops;
			//ViewLoop& pointerToStartOfLoopData;
			//uint8_t currentCel;
			//uint8_t numberOfCels;
			//ViewCell& pointerToStartOfCelData;
			//uint16_t pointerToStartOfCelDataAgain; // not sure why this is duplicated, it is in the specs. It can probably be made a ViewCel if the interpreter actually uses it.
			//uint16_t copyOfX;
			//uint16_t copyOfY;
			//uint16_t xSize;
			//uint16_t ySize;
			//uint8_t stepSize;
			//uint16_t cycleTime;
			//ViewDirection direction;
			//ViewMotion motion;
			//ViewCycle cycle;
			ViewFlags flags;
		};
	}
}