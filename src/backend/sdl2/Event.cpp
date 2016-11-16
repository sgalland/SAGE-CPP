#include "Event.h"

std::map<SDL_EventType, EventType> Event::eventMap;
bool Event::isEventTypeInitialized = false;

void Event::initializeEventTypeEnum()
{
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_QUIT, EventType::QUIT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_WINDOWEVENT, EventType::WINDOW_EVENT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_KEYDOWN, EventType::KEYBOARD_EVENT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_KEYUP, EventType::KEYBOARD_EVENT));

	isEventTypeInitialized = true;
}

Event Event::pollEvent()
{
	if (!isEventTypeInitialized)
		initializeEventTypeEnum();

	SDL_Event event;
	SDL_PollEvent(&event);

	Event retEvent;
	if (eventMap.find(static_cast<SDL_EventType>(event.type)) != eventMap.end())
		retEvent.eventType = eventMap[static_cast<SDL_EventType>(event.type)];
	else
		retEvent.eventType = EventType::NOT_SET;

	return retEvent;
}
