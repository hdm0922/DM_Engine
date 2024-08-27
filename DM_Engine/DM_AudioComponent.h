#pragma once
#include "DM_Component.h"





namespace DM
{
    class AudioComponent;
}





class DM::AudioComponent :
    public Component
{

public:

    AudioComponent(const GameObject* owner, const std::wstring& name = L"");
    virtual ~AudioComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;
};

