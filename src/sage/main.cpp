//#ifdef define(WIN32) && define(_DEBUG)
#include <vld.h>
//#endif

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

	std::vector<DisplayMode> modes = engine.graphics->getDisplayModes();

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
			if ((Keyboard::isKeyDown(Key::LeftShift) || Keyboard::isKeyDown(Key::RightShift)) && Keyboard::isKeyDown(Key::Enter))
				if (!engine.graphics->getIsFullscreen())
					engine.graphics->fullscreen();
				else engine.graphics->windowed();
			break;
		}

		t[rand() % (320 * 200)] = rand() % 250000;
		engine.graphics->clear(255, 255, 255);
		engine.graphics->push(&t);
		engine.graphics->render();
	}

	return 0;
}