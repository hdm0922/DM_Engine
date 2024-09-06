#include "SDV_GameStateComponent.h"





SDV::GameStateComponent::GameStateComponent(const DM::GameObject* owner, const std::wstring& name)
	: DM::Component(owner, name, DM::Enums::ComponentType::State)
	, blocksPlayer(false)
{
}





SDV::GameStateComponent::~GameStateComponent()
{
}





void SDV::GameStateComponent::Initialize()
{
}





void SDV::GameStateComponent::Update()
{
}
