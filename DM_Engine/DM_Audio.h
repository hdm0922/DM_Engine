#pragma once
#include "DM_Resource.h"





namespace DM
{
    class Audio;
}





class DM::Audio :
    public Resource
{

public:

	Audio(const std::wstring& path, const std::wstring& name = L"");
	virtual ~Audio() override;

	virtual void Load() override;

	void Play();
	void Stop();
	void SetAttributes_2D(Math::Vector2<FLOAT>& position);


public:

	FMOD::Sound* GetSound() const { return this->sound; }
	FMOD::Channel* GetChannel() const { return this->channel; }


private:

	FMOD::Sound* sound;
	FMOD::Channel* channel;

	FLOAT minDistance;
	FLOAT maxDistance;


};

