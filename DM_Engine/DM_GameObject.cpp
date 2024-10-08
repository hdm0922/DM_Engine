#include "DM_GameObject.h"

#include "DM_TransformComponent.h"
#include "DM_RenderComponent.h"
#include "DM_RigidBodyComponent.h"
#include "DM_ColliderComponent.h"
#include "DM_ResourceManager.h"
#include "DM_Animation.h"





DM::GameObject::GameObject(const std::wstring& name)
	: Entity(name)
	, components({})
	, originSize()
{
	this->AddComponent<TransformComponent>();
	this->AddComponent<RigidBodyComponent>();
}





DM::GameObject::~GameObject()
{
}





void DM::GameObject::Initialize()
{
	for (Component* component : this->components)
	{
		component->Initialize();
	}
}





void DM::GameObject::Update()
{
	for (Component* component : this->components)
	{
		component->Update();
	}
}





void DM::GameObject::Render(HDC hdc) const
{
	RenderComponent* renderer =
		this->GetComponent<RenderComponent>();

	if (renderer) { renderer->Render(hdc); }

	// DEBUG

	ColliderComponent* collider =
		this->GetComponent<ColliderComponent>();

	if (collider) { collider->Render(hdc); }

	// END


}





void DM::GameObject::Destroy()
{
}





void DM::GameObject::SetPosition(const Math::Vector2<FLOAT> position) const
{
	this->GetComponent<TransformComponent>()->SetPosition(position);
}





DM::Math::Vector2<FLOAT> DM::GameObject::GetSize() const
{

	Math::Vector2<FLOAT> scale = this->GetComponent<TransformComponent>()->GetScale();

	return Math::Vector2<FLOAT>(
		this->GetOriginalSize().x * scale.x,
		this->GetOriginalSize().y * scale.y
	);
}





DM::Math::Vector2<FLOAT> DM::GameObject::GetPosition() const
{
	return this->GetComponent<TransformComponent>()->GetPosition();
}