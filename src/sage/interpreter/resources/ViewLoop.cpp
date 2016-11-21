#include "ViewLoop.h"

uint8_t ViewLoop::getLoopID()
{
	return this->loopID;
}

std::vector<ViewCell> &ViewLoop::cels()
{
	return this->loopCels;
}

void ViewLoop::setLoopID(uint8_t loopID)
{
	this->loopID = loopID;
}
