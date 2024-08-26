#pragma once
#include "DM_Resource.h"





namespace DM
{
    class Animation;
    class Texture;
    
    struct Sprite;
}





class DM::Animation :
    public Resource
{

public:

    Animation(const std::wstring& path, const std::wstring& name);
    virtual ~Animation() override;

    virtual void Load() override;
    
    void LoadAnimation(Texture* spriteSheet, Sprite* firstSpriteInfo, UINT numberOfSprites, FLOAT spriteDuration);
    void MoveToNextSprite(BOOL hasLoop);


public:

    Texture* GetTexture() const { return this->spriteSheet; }
    Sprite* GetCurrentSprite() const { return this->sprites[currentIndex]; }
    FLOAT GetSpriteDuration() const { return this->spriteDuration; }


private:

    Texture* spriteSheet;
    std::vector<Sprite*> sprites;

    UINT currentIndex;
    FLOAT spriteDuration;


};

