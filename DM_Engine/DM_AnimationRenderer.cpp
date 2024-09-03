#include "DM_AnimationRenderer.h"

#include "DM_GameObject.h"
#include "DM_Animation.h"
#include "DM_Texture.h"
#include "DM_Sprite.h"
#include "DM_Time.h"
#include "DM_Camera.h"
#include "DM_TransformComponent.h"
#include "DM_ResourceManager.h"
#include "DM_SceneManager.h"





DM::AnimationRenderer::AnimationRenderer(const GameObject* owner, const std::wstring& name)
	: RenderComponent(owner, name)
	, currentAnimation(nullptr)
	, loopCurrentAnimation(false)
	, timeRenderedCurrentSprite(0.0f)
{
}





DM::AnimationRenderer::~AnimationRenderer()
{
}





void DM::AnimationRenderer::Initialize()
{
}





void DM::AnimationRenderer::Update()
{

	RenderComponent::Update();

	if (!this->currentAnimation) return;

	this->timeRenderedCurrentSprite += Time::GetDeltaTime();

	if (this->timeRenderedCurrentSprite <
		this->currentAnimation->GetSpriteDuration()) return;

	this->timeRenderedCurrentSprite = 0.0f;
	this->currentAnimation->MoveToNextSprite(this->loopCurrentAnimation);

	return;
}





void DM::AnimationRenderer::Render(HDC hdc) const
{

	if (!this->currentAnimation) return;

	switch (this->currentAnimation->GetTexture()->GetTextureType())
	{
	case Enums::TextureType::bmp: this->render_bmp(hdc); break;
	case Enums::TextureType::png: this->render_png(hdc); break;
	}

	return;
}





void DM::AnimationRenderer::Play(const std::wstring& name, BOOL hasLoop)
{

	Animation* animation = ResourceManager::GetResource<Animation>(name);

	if (!animation) return;

	this->currentAnimation = animation;
	this->loopCurrentAnimation = hasLoop;
	this->timeRenderedCurrentSprite = 0.0f;

	return;
}





void DM::AnimationRenderer::render_bmp(HDC hdc) const
{

	Sprite* sprite = this->currentAnimation->GetCurrentSprite();

	Math::Vector2<FLOAT> topLeft_relative = this->GetOwner()->GetTopLeft()
		- SceneManager::GetActiveScene()->GetCamera()->GetTopLeft();

	TransparentBlt(

		hdc,
		static_cast<INT>(topLeft_relative.x),
		static_cast<INT>(topLeft_relative.y),
		static_cast<INT>(this->GetOwner()->GetSize().x),
		static_cast<INT>(this->GetOwner()->GetSize().y),

		this->currentAnimation->GetTexture()->GetDeviceContext(),
		sprite->topLeft.x + sprite->offset.x,
		sprite->topLeft.y + sprite->offset.y,
		static_cast<INT>(this->GetOwner()->GetOriginalSize().x),
		static_cast<INT>(this->GetOwner()->GetOriginalSize().y),

		RGB(255, 0, 255)
	);

	return;
}





void DM::AnimationRenderer::render_png(HDC hdc) const
{

	Texture* texture = this->currentAnimation->GetTexture();
	Sprite* sprite = this->currentAnimation->GetCurrentSprite();

	Math::Vector2<FLOAT> topLeft_relative = this->GetOwner()->GetTopLeft()
		- SceneManager::GetActiveScene()->GetCamera()->GetTopLeft();



	Gdiplus::ImageAttributes image_attribute = {};

	// 투명화 시킬 색의 범위 지정
	image_attribute.SetColorKey(
		Gdiplus::Color(255, 0, 255),
		Gdiplus::Color(255, 0, 255)
	);


	Gdiplus::Graphics graphics(hdc);

	graphics.DrawImage(
		texture->GetImage(),

		Gdiplus::Rect(
			static_cast<INT>(topLeft_relative.x),
			static_cast<INT>(topLeft_relative.y),
			static_cast<INT>(this->GetOwner()->GetSize().x),
			static_cast<INT>(this->GetOwner()->GetSize().y)
		),

		sprite->topLeft.x,
		sprite->topLeft.y,
		static_cast<INT>(sprite->size.x),
		static_cast<INT>(sprite->size.y),

		Gdiplus::UnitPixel,
		&image_attribute
	);

	return;
}
