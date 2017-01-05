#include "ViewTableEntry.h"

sage::agi::ViewTableEntry::ViewTableEntry(uint8_t viewID, AgiView * view)
{
	this->currentView = viewID;
	this->startOfData = view;
	this->numberOfLoops = view->getViewLoops().size();
	this->currentLoop = 0;
	this->pointerToStartOfLoopData = &view->getViewLoops().at(0);
	this->numberOfCels = view->getViewLoops().at(0).cels().size();
	this->currentCel = 0;
	this->pointerToStartOfCelData = &view->getViewLoops().at(0).cels().at(0);
}
