#pragma once
#include <map>
#include <SDL.h>

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
	RightControl
};

template<typename IntegerKeyCodeType, typename APIKeyCodeType>
class BaseKeyboard
{
protected:
	static IntegerKeyCodeType keystate;
	static std::map<Key, APIKeyCodeType> keyboardMapping;
	static bool isInitialized;
public:
	static void initialize();
	static void getKeyState();
	static bool isKeyUp(Key key);
	static bool isKeyDown(Key key);
};