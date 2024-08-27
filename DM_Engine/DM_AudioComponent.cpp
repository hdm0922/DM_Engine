#include "DM_AudioComponent.h"





DM::AudioComponent::AudioComponent(
	const GameObject* owner,
	const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::Audio)
{
}





DM::AudioComponent::~AudioComponent()
{
}





void DM::AudioComponent::Initialize()
{
	Component::Initialize();
}





void DM::AudioComponent::Update()
{
	Component::Update();
}
