#include "DM_ColliderComponent.h"

#include "DM_GameObject.h"
#include "DM_ScriptComponent.h"
#include "DM_TransformComponent.h"





DM::ColliderComponent::ColliderComponent(
	const GameObject* owner,
	const std::wstring& name,
	const Enums::ColliderType colliderType)
	: Component(owner, name, Enums::ComponentType::Collider)
	, colliderType(colliderType)
	, colliderPosition_relative({0,0})
	, colliderSize(owner->GetOriginalSize())
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





DM::Math::Vector2<FLOAT> DM::ColliderComponent::GetColliderPosition() const
{
	return this->GetOwner()->GetPosition() + this->colliderPosition_relative;
}





DM::Math::Vector2<FLOAT> DM::ColliderComponent::GetColliderSize() const
{
	Math::Vector2<FLOAT> scale = this->GetOwner()->GetComponent<TransformComponent>()->GetScale();

	return Math::Vector2<FLOAT>(
		this->colliderSize.x * scale.x,
		this->colliderSize.y * scale.y
	);
}
