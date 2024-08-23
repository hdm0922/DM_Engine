#include "DM_UI_Button.h"

#include "DM_Input.h"
#include "DM_RandomGenerator.h"



DM::UI_Button::UI_Button(const std::wstring& name)
	: UI_Frame(name)
{

}





DM::UI_Button::~UI_Button()
{
}





void DM::UI_Button::Initialize()
{

	this->topLeft = { 100.0f, 100.0f };
	this->size = { 100.0f, 100.0f };

	UI_Frame::Initialize();

	return;
}





void DM::UI_Button::Update()
{


	if (Input::GetKeyPressed(VK_LBUTTON))
	{
		BOOL cursorInButton = Math::CollisionChecker::Point_Box_2D(
			Input::GetCursorPosition(),
			this->topLeft, this->topLeft + this->size
		);

		if (cursorInButton) { this->OnEvent_Click(); }		
	}

	UI_Frame::Update();

	return;
}





void DM::UI_Button::Render(HDC hdc) const
{

	Math::Vector2<FLOAT> bottomRight = this->topLeft + this->size;

	Rectangle(hdc, (INT)topLeft.x, (INT)topLeft.y, (INT)bottomRight.x, (INT)bottomRight.y);

	UI_Frame::Render(hdc);

	return;
}





void DM::UI_Button::Destroy()
{

	UI_Frame::Destroy();

	return;
}





void DM::UI_Button::OnEvent_Click()
{

	if (this->clickEvent) { this->clickEvent(); }
	
	return;
}





void DM::UI_Button::load()
{
}