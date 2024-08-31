#pragma once
#include "DM_Component.h"





namespace DM
{
    class ScriptComponent;
}





class DM::ScriptComponent :
    public Component
{

public:

    ScriptComponent(const GameObject* owner, const std::wstring& name = L"");
    virtual ~ScriptComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;


};

