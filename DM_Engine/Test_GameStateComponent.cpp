#include "Test_GameStateComponent.h"





Test::GameStateComponent::GameStateComponent(const DM::GameObject* owner, const std::wstring& name)
	: DM::Component(owner, name, DM::Enums::ComponentType::State)
	, blocksPlayer(false)
{
}





Test::GameStateComponent::~GameStateComponent()
{
}





void Test::GameStateComponent::Initialize()
{
}





void Test::GameStateComponent::Update()
{
}
