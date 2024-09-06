#pragma once
#include "framework.h"

#include "DM_Application.h"





namespace DM
{
	class Input;
	class Application;
	class Window;
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

	struct DragEvent
	{
		BOOL valid;
		Math::Vector2<FLOAT> startPosition;
		Math::Vector2<FLOAT> endPosition;
	};


public:

	static void Initialize();
	static void Update();


public:

	static BOOL GetKeyHold(INT keyCode, Window* activeWindow = Application::GetMainWindow());
	static BOOL GetKeyReleased(INT keyCode, Window* activeWindow = Application::GetMainWindow());
	static BOOL GetKeyPressed(INT keyCode, Window* activeWindow = Application::GetMainWindow());

	static BOOL GetKeysPressed(std::vector<INT>& keyCodes, Window* activeWindow = Application::GetMainWindow());
	static BOOL GetKeysReleased(std::vector<INT>& keyCodes, Window* activeWindow = Application::GetMainWindow());

	static DragEvent GetDragEvent() { return Input::dragEvent; }
	static Math::Vector2<FLOAT> GetCursorPosition() { return Input::cursorPosition; }


private:

	static void createKeys();
	static void updateKey(Key& key);

	static void checkDragEvent();
	static void updateCursor();

	static void updateKeyState_Up(Key& key);
	static void updateKeyState_Pressed(Key& key);

	static void resetKeyStates();
	static void resetKeyState(Key& key);


private:

	static std::vector<Key> keys;
	static Math::Vector2<FLOAT> cursorPosition;
	static DragEvent dragEvent;


};

