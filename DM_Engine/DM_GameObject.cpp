#include "DM_GameObject.h"

#include "DM_TransformComponent.h"





DM::GameObject::GameObject(const std::wstring& name)
	: Entity(name)
	, ObjectTree<GameObject>()
{
	this->AddComponent<TransformComponent>();
}





DM::GameObject::~GameObject()
{
}





void DM::GameObject::Initialize()
{
	ObjectTree<GameObject>::Initialize();
}





void DM::GameObject::Update()
{
	ObjectTree<GameObject>::Update();
}





void DM::GameObject::Render(HDC hdc) const
{
	ObjectTree<GameObject>::Render(hdc);
}





void DM::GameObject::Destroy()
{
	ObjectTree<GameObject>::Destroy();
}
