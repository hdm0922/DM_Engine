#include "DM_UI_Frame.h"

#include "DM_ComponentHolder.h"
#include "DM_TransformComponent.h"





DM::UI_Frame::UI_Frame(const std::wstring& name)
	: GameObject(name)
	, parent_UI(nullptr)
	, sub_UIs({})
	, hidden(false)
{
}





DM::UI_Frame::~UI_Frame()
{
}





void DM::UI_Frame::Initialize()
{
	this->load();

	for (UI_Frame* sub_UI : this->sub_UIs)
	{
		sub_UI->Initialize();
	}

	return;
}





void DM::UI_Frame::Update()
{

	for (UI_Frame* sub_UI : this->sub_UIs)
	{
		sub_UI->Update();
	}

	return;
}





void DM::UI_Frame::Render(HDC hdc) const
{

	for (UI_Frame* sub_UI : this->sub_UIs)
	{
		sub_UI->Render(hdc);
	}

	return;
}





void DM::UI_Frame::Destroy()
{

	for (UI_Frame* sub_UI : this->sub_UIs)
	{
		sub_UI->Destroy();
	}

	return;
}





void DM::UI_Frame::Hide()
{

    for (UI_Frame* subNode : this->sub_UIs)
    {
        subNode->Hide();
    }

    this->SetHidden(true);

}





void DM::UI_Frame::Show()
{
	this->SetHidden(false);
}





void DM::UI_Frame::SetPosition(const Math::Vector2<FLOAT> position) const
{
	this->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->SetPosition(position);
}





DM::Math::Vector2<FLOAT> DM::UI_Frame::GetPosition() const
{
	return this->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->GetPosition();
}





void DM::UI_Frame::load()
{
}