#include "DM_UI_Frame.h"





DM::UI_Frame::UI_Frame(const std::wstring& name)
	: Entity(name)
	, ObjectTree<UI_Frame>()
{
}





DM::UI_Frame::~UI_Frame()
{
}





void DM::UI_Frame::Initialize()
{
	this->load();

	ObjectTree<UI_Frame>::Initialize();

	return;
}





void DM::UI_Frame::Update()
{

	ObjectTree<UI_Frame>::Update();

	return;
}





void DM::UI_Frame::Render(HDC hdc) const
{

	ObjectTree<UI_Frame>::Render(hdc);


	return;
}





void DM::UI_Frame::Destroy()
{
	ObjectTree<UI_Frame>::Destroy();

	return;
}





void DM::UI_Frame::load()
{
}