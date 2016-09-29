#pragma once

#include <map>
#include <SDL.h>

#include "../base/BaseEvent.h"

class Event :public BaseEvent
{
private:
	static std::map<SDL_EventType, EventType> eventMap;
	static void initializeEventTypeEnum();
	static bool isEventTypeInitialized;
public:
	static Event pollEvent();
};