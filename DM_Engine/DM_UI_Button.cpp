#include "DM_UI_Button.h"

#include "DM_Input.h"




DM::UI_Button::UI_Button(const std::wstring& name)
	: UI_Frame(name)
{
}





DM::UI_Button::~UI_Button()
{
}





void DM::UI_Button::Initialize()
{
}





void DM::UI_Button::Update()
{

	if (Input::GetKeyPressed(VK_LBUTTON))
	{
		Math::Vector2<FLOAT> topLeft = { 100.0f,100.0f };
		Math::Vector2<FLOAT> bottomRight = { 200.0f,200.0f };

		if (Math::CollisionChecker::Point_Box_2D(
			Input::GetCursorPosition(),
			topLeft, bottomRight
		))
		{
			// Click Event !

			//this->Create_UI<UI_Button>();
			//Math::Vector2<FLOAT> rand = {
			//	RandomGenerator::GetRandom<FLOAT>(100.0f, 500.0f),
			//	RandomGenerator::GetRandom<FLOAT>(100.0f, 500.0f)
			//};

			int a = 0;
		}

		
	}

}





void DM::UI_Button::Render(HDC hdc)
{

	Rectangle(hdc, 100, 100, 200, 200);

	return;
}





void DM::UI_Button::Load()
{
}





void DM::UI_Button::Kill()
{
}
