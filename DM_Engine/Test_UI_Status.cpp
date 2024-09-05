#include "Test_UI_Status.h"

#include "DM_UI_Button.h"





Test::UI_Status::UI_Status(const std::wstring& name)
	: UI_Frame(name)
{
	this->SetToggleKeyCode('S');

	DM::UI_Button* closeButton = this->CreateSubUI<DM::UI_Button>();
	closeButton->SetParent_UI(this);
	closeButton->clickEvent = std::bind(&UI_Status::close, this);

	closeButton->SetPosition(200,0);
	closeButton->SetOriginalSize(50, 50);

}





Test::UI_Status::~UI_Status()
{
}





void Test::UI_Status::Initialize()
{
	DM::UI_Frame::Initialize();
}





void Test::UI_Status::Update()
{
	DM::UI_Frame::Update();
}





void Test::UI_Status::Render(HDC hdc) const
{
	if (this->GetHidden()) return;

	Rectangle(hdc, 100, 100, 200, 200);

	UI_Frame::Render(hdc);
}





void Test::UI_Status::Destroy()
{
	DM::UI_Frame::Destroy();
}





void Test::UI_Status::load()
{
}
