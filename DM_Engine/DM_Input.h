#pragma once
#include "framework.h"



namespace DM
{
	class Input;
}



class DM::Input
{

public:

	struct Key
	{
		INT keyCode;
		Enums::KeyState keyState;
		BOOL keyHold;
	};


public:

	static void Initialize();
	static void Update();


public:

	static BOOL GetKeyHold(int keyCode)		{ return Input::keys[keyCode].keyState == Enums::KeyState::Hold; }
	static BOOL GetKeyUp(int keyCode)		{ return Input::keys[keyCode].keyState == Enums::KeyState::Up; }
	static BOOL GetKeyPressed(int keyCode)	{ return Input::keys[keyCode].keyState == Enums::KeyState::Pressed; }

	static Math::Vector2<FLOAT> GetCursorPosition() { return Input::cursorPosition; }


private:

	static void createKeys();
	static void updateKey(Key& key);
	static void updateCursor();
	static void updateKeyState_Up(Key& key);
	static void updateKeyState_Pressed(Key& key);
	static void resetKeyStates();
	static void resetKeyState(Key& key);


private:

	static std::vector<Key> keys;
	static Math::Vector2<FLOAT> cursorPosition;
};

