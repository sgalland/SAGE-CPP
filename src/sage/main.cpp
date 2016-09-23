#ifdef WIN32 && _DEBUG
#include <vld.h>
#endif

#include <iostream>

#include "interpreter\AgiInterpreter.h"
#include "interpreter\logic\LogicProcessor.h"

#include <boost/filesystem.hpp>

namespace game = sage::agi;
namespace fs = boost::filesystem;


int main()
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

	game::LogicProcessor processor;
	processor.Execute(0);

	return 0;
}