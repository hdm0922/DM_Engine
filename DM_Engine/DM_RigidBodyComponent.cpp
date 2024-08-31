#include "DM_RigidBodyComponent.h"

#include "DM_Time.h"
#include "DM_GameObject.h"
#include "DM_TransformComponent.h"





DM::RigidBodyComponent::RigidBodyComponent(const GameObject* owner, const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::RigidBody)
	, velocity({0.0f, 0.0f})
	, accel({ 0.0f, 0.0f })
	, mass(1.0)
	, simulatePhysics(false)
{
}





DM::RigidBodyComponent::~RigidBodyComponent()
{
}





void DM::RigidBodyComponent::Initialize()
{
	Component::Initialize();
}





void DM::RigidBodyComponent::Update()
{

	TransformComponent* transform =
		this->GetOwner()->GetComponent<TransformComponent>();

	Math::Vector2<FLOAT> position = transform->GetPosition();
	position += this->GetVelocity() * Time::GetDeltaTime();
	transform->SetPosition(position);

	if (this->SimulatingPhysics())
		this->updatePhysics();


	Component::Update();
}





void DM::RigidBodyComponent::updatePhysics()
{

	return;
}
