#pragma once

#include <map>
#include <SDL.h>

enum class EventType
{
	NOT_SET,
	QUIT,
	WINDOW_EVENT,
	KEYBOARD_EVENT
};

class Event
{
private:
	static std::map<SDL_EventType, EventType> eventMap;
	static void initializeEventTypeEnum();
	static bool isEventTypeInitialized;
	EventType eventType;
public:
	static Event pollEvent();
	EventType getEventType();
};