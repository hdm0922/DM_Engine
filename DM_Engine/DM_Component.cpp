#include "DM_Component.h"





DM::Component::Component(const std::wstring& name, const Enums::ComponentType componentType)
	: Entity(name)
	, componentType(componentType)
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





void DM::Component::Render(HDC hdc)
{
}
