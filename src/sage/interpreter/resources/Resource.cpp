#include "Resource.h"



Resource::Resource(AgiFile file, uint8_t resourceID)
{
	this->file = file;
	this->resourceID = resourceID;
}


Resource::~Resource()
{
}
