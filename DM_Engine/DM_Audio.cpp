#include "DM_Audio.h"





DM::Audio::Audio(const std::wstring& path, const std::wstring& name)
	: Resource(path, name)
	, sound(nullptr)
	, channel(nullptr)
	, minDistance(0.5f)
	, maxDistance(100.0f)
{
}





DM::Audio::~Audio()
{
	this->sound->release();
	this->sound = nullptr;
}





void DM::Audio::Load()
{

	if (!FMod::CreateSound(this->GetPath(), &this->sound)) return;

	this->sound->set3DMinMaxDistance(this->minDistance, this->maxDistance);

	return;
}





void DM::Audio::SetAttributes_2D(Math::Vector2<FLOAT>& position)
{
	FMOD_VECTOR Fposition = { position.x, position.y, 0.0f };
	FMOD_VECTOR Fvelocity = { 0.0f, 0.0f, 0.0f };

	this->channel->set3DAttributes(&Fposition, &Fvelocity);
}
