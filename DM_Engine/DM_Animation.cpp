#include "DM_Animation.h"

#include "DM_ResourceManager.h"





DM::Animation::Animation(const std::wstring& path, const std::wstring& name)
	: Resource(path, name)
	, spriteSheet(nullptr)
	, sprites({})
	, currentIndex(0)
	, spriteDuration(0.0f)
{
}





DM::Animation::~Animation()
{
}





void DM::Animation::Load()
{
}





void DM::Animation::LoadAnimation(
	Texture* spriteSheet,
	Sprite* firstSpriteInfo,
	UINT numberOfSprites,
	FLOAT spriteDuration)
{

	this->spriteSheet = spriteSheet;
	this->spriteDuration = spriteDuration;

	for (UINT iter = 0; iter < numberOfSprites; iter++)
	{
		Sprite* sprite = new Sprite(
			firstSpriteInfo->topLeft,
			firstSpriteInfo->size,
			firstSpriteInfo->offset
		);

		sprite->topLeft.x += sprite->size.x * iter;

		this->sprites.push_back(sprite);
	}

	return;
}





void DM::Animation::MoveToNextSprite()
{

	this->currentIndex++;
	if (this->currentIndex == this->sprites.size()) { this->currentIndex = 0; }

}
