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





void DM::ColliderComponent::CollisionEvent_Enter(const GameObject* other)
{
}





void DM::ColliderComponent::CollisionEvent_Collide(const GameObject* other)
{
}





void DM::ColliderComponent::CollisionEvent_Exit(const GameObject* other)
{
	int a = 0;
}
