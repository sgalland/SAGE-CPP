#include "MenuBar.h"
#include <SDL.h>

MenuBar::MenuBar(AgiInterpreter * interpreter)
{
	this->output = new Texture(0, 0, MENUBAR_WIDTH, MENUBAR_HEIGHT);
}

void MenuBar::Update()
{
	
}
