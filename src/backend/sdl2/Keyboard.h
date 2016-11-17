#pragma once
#include <SDL.h>
#include <map>

enum class Key
{
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Backspace,
	LeftAlt,
	RightAlt,
	LeftShift,
	RightShift,
	LeftControl,
	RightControl,
	Enter
};

class Keyboard
{
private:
	static void initialize();
	static Uint8* keystate;
	static std::map<Key, SDL_Scancode> keyboardMapping;
	static bool isInitialized;
public:
	static void getKeyState();
	static bool isKeyUp(Key key);
	static bool isKeyDown(Key key);

};