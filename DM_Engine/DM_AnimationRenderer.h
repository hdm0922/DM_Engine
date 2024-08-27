#pragma once
#include "DM_RenderComponent.h"





namespace DM
{
    class AnimationRenderer;
    class Animation;
}





class DM::AnimationRenderer :
    public RenderComponent
{

public:

    AnimationRenderer(const GameObject* owner,
        const std::wstring& name = L"");

    virtual ~AnimationRenderer() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;

    void Play(const std::wstring& name, BOOL hasLoop);


public:

    Animation* GetCurrentAnimation() const { return this->currentAnimation; }
    BOOL GetLoopCurrentAnimation() const { return this->loopCurrentAnimation; }


private:

    void render_bmp(HDC hdc) const;
    void render_png(HDC hdc) const;


private:

    Animation* currentAnimation;
    BOOL loopCurrentAnimation;
    FLOAT timeRenderedCurrentSprite;


};

