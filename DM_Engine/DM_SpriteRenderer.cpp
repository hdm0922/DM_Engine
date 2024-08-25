#include "DM_SpriteRenderer.h"

#include "DM_Texture.h"





DM::SpriteRenderer::SpriteRenderer(const GameObject* owner, const std::wstring& name)
	: RenderComponent(owner, name)
	, texture(nullptr)
{
}





DM::SpriteRenderer::~SpriteRenderer()
{
}





void DM::SpriteRenderer::Initialize()
{
}





void DM::SpriteRenderer::Update()
{
}





void DM::SpriteRenderer::Render(HDC hdc) const
{
}
