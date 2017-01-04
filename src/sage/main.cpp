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
#include "../backend/sdl2/BitmapFont.h"

#include "interpreter/resources/Views/ViewFlags.h"
#include "interpreter/resources/Views/ViewLoop.h"
#include "interpreter/resources/AgiFileReader.h"
#include "interpreter/resources/AgiView.h"
#include "interpreter/resources/AgiPicture.h"
#include "interpreter/gui/menu/MenuBar.h"
#include "interpreter/helpers/AgiColorConverter.h"

#include <SDL.h>


namespace game = sage::agi;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	fs::current_path("C:\\Users\\sgalland\\Desktop\\Stuff\\The Black Cauldron.1987");
	std::cout << "Emulating AGI version: " << game::AgiVersion::GetVersion() << std::endl;
	std::cout << "Game ID: " << game::AgiVersion::GetGameID() << std::endl;

	Engine engine(320, 200);
	engine.graphics->setWindowTitle("SAGE - " + game::AgiVersion::GetGameID() + " v" + game::AgiVersion::GetVersion());

	AgiInterpreter interpreter;

	AgiFileReader pictureReader(AgiFileType::Picture);
	std::vector<AgiDirectoryEntry> entries = pictureReader.GetDirectoryEntries();
	AgiPicture pic(pictureReader.GetFile(71));
	Texture t(0, 9, 320, 200);
	std::vector<uint32_t> picBuffer(320 * 200);
	memcpy(&picBuffer[0], pic.pictureBuffer, 320 * 200 * sizeof(picBuffer[0]));
	t.setData(AgiColorConverter::convertVectorDosColorToVectorUint32(t, picBuffer));

	AgiFileReader reader(AgiFileType::View);
	std::vector<AgiDirectoryEntry> entries1 = reader.GetDirectoryEntries();
	AgiView view(reader.GetFile(0));
	ViewCell cel = view.getViewLoops().at(0).cels().at(0);
	auto width = cel.getWidth();
	auto height = cel.getHeight();
	Texture taran(0, 120, width, height);
	AgiColor trans = cel.getTransparentColor();
	taran.setTransparentColor(AgiColorConverter::toUint32(taran, trans));

	game::LogicProcessor processor;
	processor.Execute(0);

	MenuBar menuBar(engine, interpreter);

	bool isRunning = true;
	int x = 0, y = 0;
	while (isRunning)
	{
		Event event = Event::pollEvent();

		cel = view.getViewLoops().at(0).cels().at(x);
		taran.setData(AgiColorConverter::convertVectorDosColorToVectorUint32(taran, cel.getData()));

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
		engine.graphics->push(&taran);
		menuBar.Update();
		engine.graphics->render();
	}

	return 0;
}