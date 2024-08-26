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
	, componentHolder(new ComponentHolder(this))
{

}





DM::GameObject::~GameObject()
{
}





void DM::GameObject::Initialize()
{
}





void DM::GameObject::Update()
{
}





void DM::GameObject::Render(HDC hdc) const
{
	RenderComponent* renderComponent =
		this->GetComponentHolder()->GetComponent<RenderComponent>();

	if (renderComponent) { renderComponent->Render(hdc); }
}





void DM::GameObject::Destroy()
{
}





void DM::GameObject::RegisterAnimation(const std::wstring& name)
{

	Animation* animation = ResourceManager::GetResource<Animation>(name);
	if (!animation) return;

	GameObject::animationPool.insert({name, animation});
}





void DM::GameObject::SetPosition(const Math::Vector2<FLOAT> position) const
{
	this->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->SetPosition(position);
}





DM::Math::Vector2<FLOAT> DM::GameObject::GetPosition() const
{
	return this->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->GetPosition();
}
