#pragma once
#include "../base/BaseKeyboard.h"
#include <SDL.h>

class Keyboard : public BaseKeyboard<Uint8*, SDL_Scancode>
{
private:
	static void initialize();
public:
	// Inherited via BaseKeyboard
	static void getKeyState();
	static bool isKeyUp(Key key);
	static bool isKeyDown(Key key);

};