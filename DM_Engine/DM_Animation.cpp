#include "DM_Animation.h"





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





void DM::Animation::MoveToNextSprite()
{

	this->currentIndex++;
	if (this->currentIndex == this->sprites.size()) { this->currentIndex = 0; }

}
