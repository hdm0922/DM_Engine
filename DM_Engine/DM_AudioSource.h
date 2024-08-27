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

    AudioSource(const GameObject* owner,
        const std::wstring& name = L"");

    virtual ~AudioSource() override;

    virtual void Initialize() override;
    virtual void Update() override;

    void Play() const;
    void Stop() const;


public:

    void SetAudio(Audio* audio) { this->audio = audio; }

    Audio* GetAudio() const { return this->audio; }


private:

    Audio* audio;
    BOOL loopAudio;

};

