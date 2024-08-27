#include "DM_GameObject.h"

#include "DM_ComponentHolder.h"
#include "DM_TransformComponent.h"
#include "DM_RenderComponent.h"
#include "DM_ResourceManager.h"
#include "DM_Animation.h"




namespace DM
{
	std::map<const std::wstring, Animation*> GameObject::animationPool = {};
}





DM::GameObject::GameObject(const std::wstring& name)
	: Entity(name)
	, components({})
{
	this->AddComponent<TransformComponent>();
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
	RenderComponent* renderComponent =
		this->GetComponent<RenderComponent>();

	if (renderComponent) { renderComponent->Render(hdc); }
}





void DM::GameObject::Destroy()
{
}





DM::Animation* DM::GameObject::GetAnimation(const std::wstring& name) const
{

	auto iter = GameObject::animationPool.find(name);

	return (iter == GameObject::animationPool.end()) ?
		nullptr : iter->second;
}





void DM::GameObject::RegisterAnimation(const std::wstring& name)
{

	Animation* animation = ResourceManager::GetResource<Animation>(name);
	if (!animation) return;

	GameObject::animationPool.insert({name, animation});
}





void DM::GameObject::SetPosition(const Math::Vector2<FLOAT> position) const
{
	this->GetComponent<TransformComponent>()->SetPosition(position);
}





DM::Math::Vector2<FLOAT> DM::GameObject::GetPosition() const
{
	return this->GetComponent<TransformComponent>()->GetPosition();
}
