#include "DM_ColliderComponent.h"

#include "DM_GameObject.h"
#include "DM_ScriptComponent.h"





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
	ScriptComponent* script = this->GetOwner()->GetComponent<ScriptComponent>();
	if (script) script->CollisionEvent_Enter(other);

	return;
}





void DM::ColliderComponent::CollisionEvent_Collide(const GameObject* other)
{
	ScriptComponent* script = this->GetOwner()->GetComponent<ScriptComponent>();
	if (script) script->CollisionEvent_Collide(other);

	return;
}





void DM::ColliderComponent::CollisionEvent_Exit(const GameObject* other)
{
	ScriptComponent* script = this->GetOwner()->GetComponent<ScriptComponent>();
	if (script) script->CollisionEvent_Exit(other);

	return;
}
