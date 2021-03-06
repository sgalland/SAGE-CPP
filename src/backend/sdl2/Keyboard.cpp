#include "Keyboard.h"

#ifdef LINUX
#include <SDL2/SDL.h>
#elif WIN32
#include <SDL.h>
#endif

Uint8* Keyboard::keystate = NULL;
std::map<Key, SDL_Scancode> Keyboard::keyboardMapping;
bool Keyboard::isInitialized = false;

void Keyboard::initialize()
{
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::A, SDL_SCANCODE_A));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::B, SDL_SCANCODE_B));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::C, SDL_SCANCODE_C));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::Enter, SDL_SCANCODE_RETURN));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::LeftShift, SDL_SCANCODE_LSHIFT));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::RightShift, SDL_SCANCODE_RSHIFT));

	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::UpArrow, SDL_SCANCODE_UP));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::DownArrow, SDL_SCANCODE_DOWN));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::LeftArrow, SDL_SCANCODE_LEFT));
	keyboardMapping.insert(std::pair<Key, SDL_Scancode>(Key::RightArrow, SDL_SCANCODE_RIGHT));

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
