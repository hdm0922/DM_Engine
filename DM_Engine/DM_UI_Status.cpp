#include "DM_UI_Status.h"

#include "DM_UI_Button.h"





DM::UI_Status::UI_Status(const std::wstring& name)
	: UI_Frame(name)
{
	UI_Button* closeButton = this->ObjectTree<UI_Frame>::Create<UI_Button>();
	//closeButton->ObjectTree<UI_Frame>::SetParent(this);

	int a = 0;
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
