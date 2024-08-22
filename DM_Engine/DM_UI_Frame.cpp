#include "DM_UI_Frame.h"





DM::UI_Frame::UI_Frame(const std::wstring& name)
	: Entity(name)
	, parent_UI(nullptr)
	, sub_UIs({})
{
}





DM::UI_Frame::~UI_Frame()
{
	
	for (UI_Frame* UI : this->sub_UIs)
	{
		delete UI;
		UI = nullptr;
	}
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

	return;
}





void DM::UI_Frame::Render(HDC hdc)
{

	for (UI_Frame* UI : this->sub_UIs)
	{
		UI->Render(hdc);
	}

	return;
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