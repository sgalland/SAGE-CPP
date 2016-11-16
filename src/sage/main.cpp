#ifdef WIN32 && _DEBUG
#include <vld.h>
#endif

#include <SDL.h>

#include <iostream>

#include "interpreter\AgiInterpreter.h"
#include "interpreter\logic\LogicProcessor.h"

#include <boost/filesystem.hpp>

#include "../backend/sdl2/Engine.h"
#include "../backend/sdl2/Graphics.h"
#include "../backend/sdl2/Event.h"
#include "../backend/sdl2/Texture.h"
#include "../backend/sdl2/Keyboard.h"

namespace game = sage::agi;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\The Black Cauldron.1987");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	Engine engine(320, 200);
	Texture t(320, 200);

	for (int i = 0; i < 320 * 200; i++)
	{
		if (i % 24 == 0)
		{
			int v = 16711680;
			t[i] = v;
		}
		else
			t[i] = 0;
	}

	game::LogicProcessor processor;
	processor.Execute(0);

	bool isRunning = true;
	while (isRunning)
	{
		Event event = Event::pollEvent();

		switch (event.getEventType())
		{
		case EventType::QUIT: isRunning = false; break;
		case EventType::KEYBOARD_EVENT:
			Keyboard::getKeyState();
			if (Keyboard::isKeyDown(Key::A) && Keyboard::isKeyDown(Key::B))
				std::cout << "A+B" << std::endl;
			break;
		}

		engine.graphics->clear(0, 0, 0);
		engine.graphics->push(&t);
		engine.graphics->render();
	}

	return 0;
}