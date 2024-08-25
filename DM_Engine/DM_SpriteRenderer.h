#pragma once
#include "DM_RenderComponent.h"





namespace DM
{
    class SpriteRenderer;
    class Texture;
}





class DM::SpriteRenderer :
    public RenderComponent
{

public:

    SpriteRenderer(const GameObject* owner, const std::wstring& name = L"");
    virtual ~SpriteRenderer() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;


private:

    Texture* texture;

};

