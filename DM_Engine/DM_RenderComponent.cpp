#include "DM_RenderComponent.h"





DM::RenderComponent::RenderComponent(const GameObject* owner, const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::Render)
{
}





DM::RenderComponent::~RenderComponent()
{
}





void DM::RenderComponent::Initialize()
{

	Component::Initialize();

	return;
}





void DM::RenderComponent::Update()
{

	Component::Update();

	return;
}