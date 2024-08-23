#include "DM_Component.h"





DM::Component::Component(
	const GameObject* owner,
	const std::wstring& name,
	const Enums::ComponentType componentType)
	: Entity(name)
	, componentType(componentType)
	, owner(owner)
{
}





DM::Component::~Component()
{
}





void DM::Component::Initialize()
{
}





void DM::Component::Update()
{
}





void DM::Component::Render(HDC hdc) const
{
}
