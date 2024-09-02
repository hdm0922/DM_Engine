#include "DM_SpriteRenderer.h"

#include "DM_GameObject.h"
#include "DM_TransformComponent.h"
#include "DM_Texture.h"
#include "DM_Sprite.h"





DM::SpriteRenderer::SpriteRenderer(const GameObject* owner, const std::wstring& name)
	: RenderComponent(owner, name)
	, texture(nullptr)
	, sprite(new Sprite())
{
}





DM::SpriteRenderer::~SpriteRenderer()
{
	delete this->texture;
	this->texture = nullptr;

	delete this->sprite;
	this->sprite = nullptr;
}





void DM::SpriteRenderer::Initialize()
{
	{
		this->sprite->topLeft = { 0,0 };
		this->sprite->size = this->GetTexture()->GetSize();
		this->sprite->offset = { 0,0 };
	}

	return;
}





void DM::SpriteRenderer::Update()
{
}





void DM::SpriteRenderer::Render(HDC hdc) const
{

	if (!this->GetTexture()) return;

	switch (this->GetTexture()->GetTextureType())
	{
	case Enums::TextureType::bmp: this->render_bmp(hdc); break;
	case Enums::TextureType::png: this->render_png(hdc); break;
	}

	return;
}





void DM::SpriteRenderer::render_bmp(HDC hdc) const
{

	const Sprite* sprite = this->GetSprite();


	TransparentBlt(

		hdc,
		static_cast<INT>(this->GetOwner()->GetTopLeft().x),
		static_cast<INT>(this->GetOwner()->GetTopLeft().y),
		static_cast<INT>(this->GetOwner()->GetSize().x),
		static_cast<INT>(this->GetOwner()->GetSize().y),

		this->GetTexture()->GetDeviceContext(),
		sprite->topLeft.x + sprite->offset.x,
		sprite->topLeft.y + sprite->offset.y,
		static_cast<INT>(this->GetOwner()->GetOriginalSize().x),
		static_cast<INT>(this->GetOwner()->GetOriginalSize().y),

		RGB(255, 0, 255)
	);

}





// 추후 수정
void DM::SpriteRenderer::render_png(HDC hdc) const
{

	TransformComponent* transform = 
		this->GetOwner()->GetComponent<TransformComponent>();


	Gdiplus::ImageAttributes image_attribute = {};

	// 투명화 시킬 색의 범위 지정
	image_attribute.SetColorKey(
		Gdiplus::Color(255, 0, 255),
		Gdiplus::Color(255, 0, 255)
	);


	Gdiplus::Graphics graphics(hdc);

	graphics.DrawImage(
		this->texture->GetImage(),

		Gdiplus::Rect(
			static_cast<INT>(this->GetOwner()->GetTopLeft().x),
			static_cast<INT>(this->GetOwner()->GetTopLeft().y),
			static_cast<INT>(texture->GetWidth() * transform->GetScale().x),
			static_cast<INT>(texture->GetHeight() * transform->GetScale().y)
		),

		0, 0,
		static_cast<INT>(texture->GetWidth()),
		static_cast<INT>(texture->GetHeight()),

		Gdiplus::UnitPixel,
		&image_attribute
	);

}
