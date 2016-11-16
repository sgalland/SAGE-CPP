#include "Keyboard.h"
#include <SDL.h>

Uint8* Keyboard::keystate = NULL;
std::map<Key, SDL_Scancode> Keyboard::keyboardMapping;
bool Keyboard::isInitialized = false;

void Keyboard::initialize()
{
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::A, SDL_SCANCODE_A));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::B, SDL_SCANCODE_B));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::C, SDL_SCANCODE_C));

	isInitialized = true;
}

void Keyboard::getKeyState()
{
	if (!isInitialized)
		initialize();

	keystate = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
}

bool Keyboard::isKeyUp(Key key)
{
	SDL_Scancode scancode = keyboardMapping[key];
	return keystate[scancode] == 0;
}

bool Keyboard::isKeyDown(Key key)
{
	SDL_Scancode scancode = keyboardMapping[key];
	return keystate[scancode] == 1;
}
