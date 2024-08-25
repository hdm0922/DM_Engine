#include "DM_SpriteRenderer.h"

#include "DM_GameObject.h"
#include "DM_TransformComponent.h"
#include "DM_Texture.h"
#include "DM_Sprite.h"





DM::SpriteRenderer::SpriteRenderer(const GameObject* owner, const std::wstring& name)
	: RenderComponent(owner, name)
	, texture(nullptr)
	, sprite(nullptr)
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

	Sprite sprite = {};
	sprite.topLeft	= { 0,0 };
	sprite.size		= this->GetTexture()->GetSize();
	sprite.offset	= { 0,0 };

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

	TransformComponent* transform = this->GetOwner()->
		GetComponentHolder()->GetComponent<TransformComponent>();

	TransparentBlt(

		hdc,
		static_cast<INT>(transform->GetPosition().x),
		static_cast<INT>(transform->GetPosition().y),
		static_cast<INT>(this->GetSprite()->size.x * transform->GetScale().x),
		static_cast<INT>(this->GetSprite()->size.y * transform->GetScale().y),

		this->GetTexture()->GetDeviceContext(),
		this->GetSprite()->topLeft.x,
		this->GetSprite()->topLeft.y,
		this->GetSprite()->size.x,
		this->GetSprite()->size.y,

		RGB(255, 0, 255)
	);

}





void DM::SpriteRenderer::render_png(HDC hdc) const
{
}
