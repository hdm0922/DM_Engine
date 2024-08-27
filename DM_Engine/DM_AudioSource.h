#pragma once
#include "DM_AudioComponent.h"





namespace DM
{
    class AudioSource;
    class Audio;
}





class DM::AudioSource :
    public AudioComponent
{

public:

    AudioSource(const GameObject* owner, const std::wstring& name = L"");
    virtual ~AudioSource() override;

    virtual void Initialize() override;
    virtual void Update() override;

    void Play(const std::wstring& name, BOOL loopAudio);
    void Stop() const;


public:

    Audio* GetAudio() const { return this->currentAudio; }


private:

    Audio* currentAudio;

};

