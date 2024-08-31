#include "DM_ColliderComponent.h"





DM::ColliderComponent::ColliderComponent(
	const GameObject* owner,
	const std::wstring& name,
	const Enums::ColliderType colliderType)
	: Component(owner, name, Enums::ComponentType::Collider)
	, colliderType(colliderType)
{
}





DM::ColliderComponent::~ColliderComponent()
{
}





void DM::ColliderComponent::Initialize()
{
	Component::Initialize();
}





void DM::ColliderComponent::Update()
{
	Component::Update();
}
