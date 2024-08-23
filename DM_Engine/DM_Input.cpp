#include "DM_Input.h"

#include "DM_Application.h"
#include "DM_Window.h"





namespace DM
{
	std::vector<Input::Key> Input::keys = {};
	Math::Vector2<FLOAT> Input::cursorPosition = {};
}





void DM::Input::Initialize()
{

	Input::createKeys();

	return;
}





void DM::Input::Update()
{

	if (!GetFocus())
	{
		Input::resetKeyStates();
		return;
	}

	for (Key& key : keys)
	{
		Input::updateKey(key);
	}

	Input::updateCursor();

	return;
}





BOOL DM::Input::GetKeyHold(int keyCode, Window* activeWindow)
{
	BOOL correctWindow = (GetActiveWindow() == activeWindow->GetHandle());
	BOOL correctKeyState = (Input::keys[keyCode].keyState == Enums::KeyState::Hold);
	return (correctWindow && correctKeyState);
}





BOOL DM::Input::GetKeyUp(int keyCode, Window* activeWindow)
{
	BOOL correctWindow = (GetActiveWindow() == activeWindow->GetHandle());
	BOOL correctKeyState = (Input::keys[keyCode].keyState == Enums::KeyState::Up);
	return (correctWindow && correctKeyState);
}





BOOL DM::Input::GetKeyPressed(int keyCode, Window* activeWindow)
{
	BOOL correctWindow = (GetActiveWindow() == activeWindow->GetHandle());
	BOOL correctKeyState = (Input::keys[keyCode].keyState == Enums::KeyState::Pressed);
	return (correctWindow && correctKeyState);
}





void DM::Input::createKeys()
{

	Input::keys = {};

	for (int iter = 0; iter <= 0xFE; iter++)
	{
		Key key = {};

		key.keyCode = iter;
		key.keyState = Enums::KeyState::None;
		key.keyHold = false;

		keys.push_back(key);
	}

	return;

}





void DM::Input::updateKey(Key& key)
{

	BOOL keyPressed = (GetAsyncKeyState(key.keyCode) & 0x8000);

	std::function<void(Key&)> UpdateKeyState = keyPressed ?
		Input::updateKeyState_Pressed : Input::updateKeyState_Up;

	UpdateKeyState(key);

	return;

}




// �ӽ� ����
void DM::Input::updateCursor()
{

	Window* mainWindow = Application::GetMainWindow();

	POINT cursorPoint = {};

	GetCursorPos(&cursorPoint);
	ScreenToClient(GetActiveWindow(), &cursorPoint);

	Input::cursorPosition = Math::Vector2<FLOAT>(
		static_cast<FLOAT>(cursorPoint.x),
		static_cast<FLOAT>(cursorPoint.y)
	);

	return;
}





void DM::Input::updateKeyState_Up(Key& key)
{

	keys[key.keyCode].keyState = key.keyHold ?
		Enums::KeyState::Up : Enums::KeyState::None;

	keys[key.keyCode].keyHold = false;

	return;
}





void DM::Input::updateKeyState_Pressed(Key& key)
{

	keys[key.keyCode].keyState = key.keyHold ?
		Enums::KeyState::Hold : Enums::KeyState::Pressed;

	keys[key.keyCode].keyHold = true;

	return;

}





void DM::Input::resetKeyStates()
{

	for (Key& key : Input::keys)
	{
		Input::resetKeyState(key);
	}

	return;
}





void DM::Input::resetKeyState(Key& key)
{

	switch (key.keyState)
	{
	case Enums::KeyState::Pressed:
		key.keyState = Enums::KeyState::Up;
		break;

	case Enums::KeyState::Hold:
		key.keyState = Enums::KeyState::Up;
		break;

	case Enums::KeyState::Up:
		key.keyState = Enums::KeyState::None;
		break;
	}

	return;

}
