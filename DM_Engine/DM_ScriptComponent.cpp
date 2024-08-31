#include "DM_ScriptComponent.h"





DM::ScriptComponent::ScriptComponent(const GameObject* owner, const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::Script)
{
}





DM::ScriptComponent::~ScriptComponent()
{
}





void DM::ScriptComponent::Initialize()
{
	Component::Initialize();
}





void DM::ScriptComponent::Update()
{
	Component::Update();
}
