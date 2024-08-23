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





void DM::Input::createKeys()
{

	Input::keys = {};

	for (int iter = 0; iter <= 0xFE; iter++)
	{
		Key key = {};

		key.keyCode = iter;
		key.keyState = Enums::keyState::None;
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




// 임시 구현
void DM::Input::updateCursor()
{

	Window* mainWindow = Application::GetMainWindow();

	POINT cursorPoint = {};

	GetCursorPos(&cursorPoint);
	ScreenToClient(mainWindow->GetHandle(), &cursorPoint);

	Input::cursorPosition = (
		(0 <= cursorPoint.x) && (cursorPoint.x <= (INT)mainWindow->GetSize().x) &&
		(0 <= cursorPoint.y) && (cursorPoint.y <= (INT)mainWindow->GetSize().y)
		) ? Math::Vector2<FLOAT>(static_cast<FLOAT>(cursorPoint.x), static_cast<FLOAT>(cursorPoint.y)) :
			Math::Vector2<FLOAT>(-1.0f);

	return;
}





void DM::Input::updateKeyState_Up(Key& key)
{

	keys[key.keyCode].keyState = key.keyHold ?
		Enums::keyState::Up : Enums::keyState::None;

	keys[key.keyCode].keyHold = false;

	return;
}





void DM::Input::updateKeyState_Pressed(Key& key)
{

	keys[key.keyCode].keyState = key.keyHold ?
		Enums::keyState::Hold : Enums::keyState::Pressed;

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
	case Enums::keyState::Pressed:
		key.keyState = Enums::keyState::Up;
		break;

	case Enums::keyState::Hold:
		key.keyState = Enums::keyState::Up;
		break;

	case Enums::keyState::Up:
		key.keyState = Enums::keyState::None;
		break;
	}

	return;

}
