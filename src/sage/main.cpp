#ifdef define(WIN32) && define(_DEBUG)
#include <vld.h>
#endif

#include <SDL.h>

#include <iostream>

#include "interpreter/AgiInterpreter.h"
#include "interpreter/logic/LogicProcessor.h"

#include <boost/filesystem.hpp>

#include "../backend/sdl2/Engine.h"
#include "../backend/sdl2/Graphics.h"
#include "../backend/sdl2/Event.h"
#include "../backend/sdl2/Texture.h"
#include "../backend/sdl2/Keyboard.h"

#include "interpreter/resources/Views/ViewLoop.h"
#include "interpreter/resources/AgiFileReader.h"
#include "interpreter/resources/AgiView.h"

namespace game = sage::agi;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	fs::current_path("C:\\Users\\s_gal\\Desktop\\Stuff\\The Black Cauldron.1987");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	Engine engine(320, 200);

	AgiFileReader reader(AgiFileType::View);
	std::vector<AgiDirectoryEntry> entries = reader.GetDirectoryEntries();

	AgiView view(reader.GetFile(entries.at(0).resourceId));
	auto width = view.getViewLoops().at(0).cels().at(0).getWidth();
	auto height = view.getViewLoops().at(0).cels().at(0).getHeight();
	
	Texture t(0, 0, width, height, view.getViewLoops().at(0).cels().at(0).getTransparentColor());


	//std::vector<DisplayMode> modes = engine.graphics->getDisplayModes();

	game::LogicProcessor processor;
	processor.Execute(0);

	bool isRunning = true;
	int x = 0, y = 0;
	while (isRunning)
	{
		Event event = Event::pollEvent();

		auto viewCel = view.getViewLoops().at(y).cels().at(x);
		t.setData(viewCel.getData());

		switch (event.getEventType())
		{
		case EventType::QUIT: isRunning = false; break;
		case EventType::KEYBOARD_EVENT:
			Keyboard::getKeyState();
			if ((Keyboard::isKeyDown(Key::LeftShift) || Keyboard::isKeyDown(Key::RightShift)) && Keyboard::isKeyDown(Key::Enter))
				if (!engine.graphics->getIsFullscreen())
					engine.graphics->fullscreen();
				else engine.graphics->windowed();
				if (Keyboard::isKeyDown(Key::UpArrow) && y < view.getViewLoops().size() - 1)
					y++;
				else if (Keyboard::isKeyDown(Key::DownArrow) && y > 0)
					y--;
				else if (Keyboard::isKeyDown(Key::LeftArrow) && x > 0)
					x--;
				else if (Keyboard::isKeyDown(Key::RightArrow) && x < view.getViewLoops().at(y).cels().size() - 1)
					x++;
				break;
		}

		engine.graphics->clear(255, 255, 255);
		engine.graphics->push(&t);
		engine.graphics->render();
	}

	return 0;
}