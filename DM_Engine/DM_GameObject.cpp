#include "DM_GameObject.h"
#include "DM_ComponentHolder.h"






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
