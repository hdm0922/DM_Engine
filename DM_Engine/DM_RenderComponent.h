#pragma once
#include "DM_Component.h"





namespace DM
{
    class RenderComponent;
}





class DM::RenderComponent abstract:
    public Component
{

public:

    RenderComponent(const GameObject* owner, const std::wstring& name = L"");
    virtual ~RenderComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const = 0;
};

