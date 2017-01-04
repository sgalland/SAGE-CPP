#include "Event.h"

std::map<SDL_EventType, EventType> Event::eventMap;
std::map<uint32_t, WindowEvent> Event::windowEventMap;
bool Event::isEventTypeInitialized = false;

void Event::initializeEventTypeEnum()
{
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_QUIT, EventType::QUIT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_WINDOWEVENT, EventType::WINDOW_EVENT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_KEYDOWN, EventType::KEYBOARD_EVENT));
	eventMap.insert(std::pair<SDL_EventType, EventType>(SDL_KEYUP, EventType::KEYBOARD_EVENT));


	windowEventMap.insert(std::pair<uint32_t, WindowEvent>(SDL_WINDOWEVENT_SIZE_CHANGED, WindowEvent::WINDOW_SIZE_CHANGED));

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

	if (retEvent.eventType == EventType::WINDOW_EVENT)
	{
		//if (windowEventMap.find(static_cast<uint32_t>(event.window.type)) != windowEventMap.end())
		//{
			retEvent.window.windowEvent = event.window;
			retEvent.window.eventType = windowEventMap[static_cast<uint32_t>(event.window.type)];
		//}
	}

	return retEvent;
}

EventType Event::getEventType()
{
	return this->eventType;
}
