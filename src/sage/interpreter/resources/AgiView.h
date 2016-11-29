#pragma once

#include <cinttypes>
#include <string>
#include <vector>

#include "../resources/AgiFileReader.h"
#include "ViewLoop.h"
#include "../../../core/BitConverter.h"

const unsigned char MAX_CEL = 255;

class AgiView
{
protected:
	uint8_t loopCount;
	std::string Description;
	int celLocations[MAX_CEL][MAX_CEL];
	int16_t loopLocations[MAX_CEL];
	int celsInLoopCount[MAX_CEL];
	//AgiColors agiColors;
	std::vector<ViewLoop> viewLoops;

	void LoadViewHeader(AgiFile file);
	void ReadLoopHeaders(AgiFile file);
	void ReadCelHeader(AgiFile file);
public:
	AgiView(AgiFile file);
	std::vector<ViewLoop> getViewLoops();
};