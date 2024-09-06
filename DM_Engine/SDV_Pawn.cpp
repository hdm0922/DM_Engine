#include "SDV_Pawn.h"

#include "DM_AnimationRenderer.h"
#include "SDV_GameStateComponent.h"





SDV::Pawn::Pawn(const std::wstring& name)
{
	this->AddComponent<DM::AnimationRenderer>();
	this->AddComponent<SDV::GameStateComponent>();
}





SDV::Pawn::~Pawn()
{
}





void SDV::Pawn::Initialize()
{
	DM::GameObject::Initialize();
}





void SDV::Pawn::Update()
{
	DM::GameObject::Update();
}





void SDV::Pawn::Render(HDC hdc) const
{
	DM::GameObject::Render(hdc);
}





void SDV::Pawn::Destroy()
{
}
