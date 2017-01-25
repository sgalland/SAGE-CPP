#include "MenuBar.h"
#include <SDL2/SDL.h>
#include "../../../../backend/sdl2/Graphics.h"
#include "../../helpers/AgiColor.h"

MenuBar::MenuBar(Engine &engine, AgiInterpreter &interpreter)
{
	this->interpreter = &interpreter;
	this->engine = &engine;

	const int pixelCount = MENUBAR_WIDTH * MENUBAR_HEIGHT;
	std::vector<uint32_t> pixels(pixelCount, 15);

	this->output = new Texture(0, 0, MENUBAR_WIDTH, MENUBAR_HEIGHT);

	//this->font = new BitmapFont("C:\\Users\\sgalland\\Desktop\\AGI Font\\A.bmp");
	//auto pp = this->font->getCharacter(0)->getData();
	//AgiColor whiteColor = AgiColor::getColorByDosColor(15);
	//uint32_t white = SDL_MapRGB(this->font->getCharacter(0)->getSDLSurface()->format, whiteColor.r, whiteColor.g, whiteColor.b);
	//for (int index = 0; index < pixelCount; index++)
	//{
	//	if (pp.size() < index && pp[index] != white)
	//		pixels[index] = pp[index];
	//}

	//this->output->setData(pixels);
}

MenuBar::~MenuBar()
{
	if (this->output != nullptr)
	{
		delete this->output;
		this->output = nullptr;
	}

	//if (this->font != nullptr)
	//{
	//	delete this->font;
	//	this->font = nullptr;
	//}
}

void MenuBar::Update()
{
	//this->engine->graphics->push(this->font->getCharacter(0));
}
