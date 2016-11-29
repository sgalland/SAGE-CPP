#pragma once

#include <vector>
#include "ViewCell.h"

class ViewLoop
{
protected:
	uint8_t loopID;
	std::vector<ViewCell> loopCels;
public:
	ViewLoop(uint8_t loopID);
	uint8_t getLoopID();
	std::vector<ViewCell> &cels();

	void setLoopID(uint8_t loopID);
};