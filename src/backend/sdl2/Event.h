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

enum class WindowEvent
{
	WINDOW_SIZE_CHANGED
};

struct Window
{
	SDL_WindowEvent windowEvent;
	WindowEvent eventType;
};

class Event
{
private:
	static std::map<SDL_EventType, EventType> eventMap;
	static std::map<uint32_t, WindowEvent> windowEventMap;
	static void initializeEventTypeEnum();
	static bool isEventTypeInitialized;
	EventType eventType;
public:
	static Event pollEvent();
	EventType getEventType();
	Window window;
};