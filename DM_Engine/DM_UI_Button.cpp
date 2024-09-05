#include "DM_UI_Button.h"

#include "DM_Input.h"
#include "DM_RandomGenerator.h"
#include "DM_TransformComponent.h"





DM::UI_Button::UI_Button(const std::wstring& name)
	: UI_Frame(name)
{

}





DM::UI_Button::~UI_Button()
{
}





void DM::UI_Button::Initialize()
{

	UI_Frame::Initialize();

	return;
}





void DM::UI_Button::Update()
{


	if (Input::GetKeyPressed(VK_LBUTTON))
	{

		BOOL cursorInButton = Math::CollisionChecker::Point_Box2D(
			Input::GetCursorPosition(),
			this->GetTopLeft(),
			this->GetBottomRight()
		);

		if (cursorInButton) { this->OnEvent_Click(); }
	}

	UI_Frame::Update();

	return;
}





void DM::UI_Button::Render(HDC hdc) const
{

	if (this->GetHidden()) return;

	auto k1 = this->GetTopLeft();
	auto k2 = this->GetBottomRight();

	Rectangle(hdc, 
		(INT)this->GetTopLeft().x, 
		(INT)this->GetTopLeft().y,
		(INT)this->GetBottomRight().x, 
		(INT)this->GetBottomRight().y
	);

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