#include "DM_GameObject.h"

#include "DM_ComponentHolder.h"
#include "DM_TransformComponent.h"





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
}





void DM::GameObject::Destroy()
{
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
