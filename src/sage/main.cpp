#ifdef WIN32 && _DEBUG
#include <vld.h>
#endif

#include <iostream>

#include "interpreter\AgiInterpreter.h"
#include "interpreter\logic\LogicProcessor.h"

#include <boost/filesystem.hpp>

#include "../backend/sdl2/Engine.h"
#include "../backend/sdl2/Graphics.h"

namespace game = sage::agi;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\The Black Cauldron.1987");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\Space Quest");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\Space Quest 2");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\Kings Quest");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\Kings Quest 2");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	//fs::current_path("C:\\Users\\s_gal\\Documents\\dbgl080\\dosroot\\The Black Cauldron.1987");
	std::cout << "Initializing SAGE..." << std::endl;
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	Engine engine(320, 200);

	game::LogicProcessor processor;
	processor.Execute(0);

	while (true)
	{
		// handle events...

		engine.graphics->clear();
		// queue sprites
		engine.graphics->render();
	}

	return 0;
}