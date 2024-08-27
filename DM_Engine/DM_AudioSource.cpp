#include "DM_AudioSource.h"
#include "DM_Audio.h"

#include "DM_ResourceManager.h"
#include "DM_GameObject.h"
#include "DM_TransformComponent.h"





DM::AudioSource::AudioSource(const GameObject* owner, const std::wstring& name)
	: AudioComponent(owner, name)
	, currentAudio(nullptr)
{
}





DM::AudioSource::~AudioSource()
{
}





void DM::AudioSource::Initialize()
{
}





void DM::AudioSource::Update()
{
	if (!this->GetAudio()) return;

	Math::Vector2<FLOAT> position =
		this->GetOwner()->GetComponentHolder()
		->GetComponent<TransformComponent>()
		->GetPosition();

	this->GetAudio()->SetAttributes_2D(position);

	return;
}





void DM::AudioSource::Play(const std::wstring& name, BOOL loopAudio)
{

	Audio* audio = ResourceManager::GetResource<Audio>(name);

	if (!audio) return;

	this->currentAudio = audio;
	audio->GetSound()->setMode(loopAudio ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF);
	FMod::PlaySound_(audio->GetSound(), audio->GetChannel());

	return;
}





void DM::AudioSource::Stop() const
{
	this->GetAudio()->GetChannel()->stop();
}
