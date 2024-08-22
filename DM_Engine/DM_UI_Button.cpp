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

	if (Input::GetKeyDown())

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
