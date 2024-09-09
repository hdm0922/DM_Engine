#pragma once
#include "DM_RenderComponent.h"





namespace DM
{
    class SpriteRenderer;
    class Texture;

    struct Sprite;
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


public:

    void SetTexture(Texture* texture) { this->texture = texture; }
    void SetSprite(Sprite* sprite) { this->sprite = sprite; }

    const Texture* GetTexture() const { return this->texture; }
    const Sprite* GetSprite() const { return this->sprite; }


private:

    void render_bmp(HDC hdc) const;
    void render_png(HDC hdc) const;


private:

    Texture* texture;
    Sprite* sprite;

    /*void (SpriteRenderer::* function_absoluteAddress)(HDC) const = &SpriteRenderer::Render;*/
};

