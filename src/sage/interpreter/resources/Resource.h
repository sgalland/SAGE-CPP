#pragma once

#include "AgiFileReader.h"

class Resource
{
protected:
	AgiFile file;
	uint8_t resourceID;
public:
	explicit Resource(AgiFile file, uint8_t resourceID);
	virtual ~Resource() = 0;
};

