#include "DM_UI_Button.h"

#include "DM_Input.h"
#include "DM_RandomGenerator.h"



DM::UI_Button::UI_Button(const std::wstring& name)
	: UI_Frame(name)
{
	this->topLeft = {
	RandomGenerator::GetRandom<FLOAT>(50.0f, 100.0f),
	RandomGenerator::GetRandom<FLOAT>(50.0f, 100.0f)
	};

	this->size = {
		RandomGenerator::GetRandom<FLOAT>(50.0f, 100.0f),
		RandomGenerator::GetRandom<FLOAT>(50.0f, 100.0f)
	};
}





DM::UI_Button::~UI_Button()
{
}





void DM::UI_Button::Initialize()
{

	this->topLeft = { 300.0f, 300.0f };

	return;
}





void DM::UI_Button::Update()
{

	if (Input::GetKeyPressed(VK_LBUTTON))
	{

		if (Math::CollisionChecker::Point_Box_2D(
			Input::GetCursorPosition(),
			this->topLeft, this->topLeft + this->size
		))
		{
			// Click Event !

			this->Create_UI<UI_Button>();

			int a = 0;
		}

		
	}

}





void DM::UI_Button::Render(HDC hdc)
{

	UI_Frame::Render(hdc);

	Math::Vector2<FLOAT> bottomRight = this->topLeft + this->size;

	Rectangle(hdc, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);

	return;
}





void DM::UI_Button::Load()
{
}





void DM::UI_Button::Kill()
{
}
