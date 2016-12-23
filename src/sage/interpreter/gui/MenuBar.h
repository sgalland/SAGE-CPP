#pragma once

#include "../AgiInterpreter.h"
#include "../../../backend/sdl2/Texture.h"

class MenuBar
{
private:
	const int MENUBAR_WIDTH = 320;
	const int MENUBAR_HEIGHT = 8;
	const std::string HEADER_FORMAT = "Score: {SCORE} of {MAX_SCORE}                       Sound: {on/off}";

	Texture *output;
public:
	MenuBar(AgiInterpreter *interpreter);
	void Update();
};