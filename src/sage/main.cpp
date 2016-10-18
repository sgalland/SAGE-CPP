#ifdef WIN32 && _DEBUG
#include <vld.h>
#endif

#include <iostream>

#include "interpreter\AgiInterpreter.h"
#include "interpreter\logic\LogicProcessor.h"

#include <boost/filesystem.hpp>

#include "../backend/sdl2/Engine.h"
#include "../backend/sdl2/Graphics.h"
#include "../backend/sdl2/Event.h"

namespace game = sage::agi;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\The Black Cauldron.1987");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	Engine engine(320, 200);

	game::LogicProcessor processor;
	processor.Execute(0);

	bool isRunning = true;
	while (isRunning)
	{
		Event event = Event::pollEvent();
		if (event.getEventType() == EventType::QUIT)
			isRunning = false;

		engine.graphics->clear(0x125, 0x125, 0x125, 0x255);
		// queue sprites
		engine.graphics->render();
	}

	return 0;
}