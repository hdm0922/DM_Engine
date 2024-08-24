#include "DM_UI_Status.h"

#include "DM_UI_Button.h"





DM::UI_Status::UI_Status(const std::wstring& name)
	: UI_Frame(name)
{
	UI_Button* closeButton = this->CreateSubUI<UI_Button>();
	closeButton->SetParent_UI(this);
	closeButton->clickEvent = std::bind(&UI_Status::close, this);

}





DM::UI_Status::~UI_Status()
{
}





void DM::UI_Status::Initialize()
{
	UI_Frame::Initialize();
}





void DM::UI_Status::Update()
{
	UI_Frame::Update();
}





void DM::UI_Status::Render(HDC hdc) const
{
	if (this->GetHidden()) return;

	Rectangle(hdc, 100, 100, 200, 200);

	UI_Frame::Render(hdc);
}





void DM::UI_Status::Destroy()
{
	UI_Frame::Destroy();
}





void DM::UI_Status::load()
{
}
