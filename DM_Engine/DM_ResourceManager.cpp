#include "DM_ResourceManager.h"

#include "DM_Animation.h"





namespace DM
{
	std::map<const std::wstring, Resource*> ResourceManager::resources = {};
}





void DM::ResourceManager::LoadAnimation(
	const std::wstring& name,
	Texture* spriteSheet,
	Sprite* firstSpriteInfo,
	UINT numberOfSprite,
	FLOAT spriteDuration)
{

	ResourceManager::LoadResource<Animation>(name, L"ANIMATION_DOESNT_NEED_A_PATH");

	Animation* animation = ResourceManager::GetResource<Animation>(name);
	animation->LoadAnimation(spriteSheet, firstSpriteInfo, numberOfSprite, spriteDuration);

	delete firstSpriteInfo;
	firstSpriteInfo = nullptr;

	return;
}
