#include "DM_UI_Frame.h"





DM::UI_Frame::UI_Frame(const std::wstring& name)
	: Entity(name)
	, sub_UIs({})
{
}





DM::UI_Frame::~UI_Frame()
{
}





void DM::UI_Frame::Initialize()
{
}





void DM::UI_Frame::Update()
{

	for (UI_Frame* UI : this->sub_UIs)
	{
		UI->Update();
	}
}





void DM::UI_Frame::Render(HDC hdc)
{

	for (UI_Frame* UI : this->sub_UIs)
	{
		UI->Render(hdc);
	}
}





void DM::UI_Frame::Load()
{
}





void DM::UI_Frame::Kill()
{

	for (UI_Frame* UI : this->sub_UIs)
	{
		UI->Kill();
	}



	return;
}