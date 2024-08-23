#include "DM_GameObject.h"





DM::GameObject::GameObject(const std::wstring& name)
	: Entity(name)
	, ObjectTree<GameObject>()
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
