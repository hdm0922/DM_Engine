#include "DM_AudioListener.h"

#include "DM_GameObject.h"
#include "DM_TransformComponent.h"





DM::AudioListener::AudioListener(const GameObject* owner, const std::wstring& name)
	: AudioComponent(owner, name)
{
}





DM::AudioListener::~AudioListener()
{
}





void DM::AudioListener::Initialize()
{
	AudioComponent::Initialize();
}





void DM::AudioListener::Update()
{
	AudioComponent::Update();

	Math::Vector2<FLOAT> position =
		this->GetOwner()->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->GetPosition();

	FMod::SetListnerAttributes_2D(position);

	return;
}
