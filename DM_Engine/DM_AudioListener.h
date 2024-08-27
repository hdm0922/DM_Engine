#pragma once
#include "DM_AudioComponent.h"





namespace DM
{
    class AudioListener;
}





class DM::AudioListener :
    public AudioComponent
{

public:

    AudioListener(const GameObject* owner, const std::wstring& name = L"");
    virtual ~AudioListener() override;

    virtual void Initialize() override;
    virtual void Update() override;
};

