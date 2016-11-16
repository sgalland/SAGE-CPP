#pragma once

enum class EventType
{
	NOT_SET,
	QUIT,
	WINDOW_EVENT,
	KEYBOARD_EVENT
};

class BaseEvent
{
protected:
	EventType eventType;
public:
	EventType getEventType();

	static BaseEvent pollEvent();
};