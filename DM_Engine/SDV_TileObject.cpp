#include "SDV_TileObject.h"

#include "DM_Sprite.h"
#include "DM_SpriteRenderer.h"
#include "DM_ResourceManager.h"





SDV::TileObject::TileObject(
	const DM::Sprite* topLeftSprite,
	const std::wstring& name)
	: DM::GameObject(name)
	, topLeftSprite(topLeftSprite)
{

	this->SetOriginalSize(SDV_TILE_SIZE);

	this->AddComponent<DM::SpriteRenderer>();
	DM::SpriteRenderer* spriteRenderer = this->GetComponent<DM::SpriteRenderer>();
	spriteRenderer->SetTexture(DM::ResourceManager::GetResource<DM::Texture>(SDV_NAME_TEXTURE_SPRING_OUTDOOR));
	spriteRenderer->SetSprite(new DM::Sprite(*topLeftSprite));
}





SDV::TileObject::~TileObject()
{
}





void SDV::TileObject::Initialize()
{
	DM::GameObject::Initialize();
}





void SDV::TileObject::Update()
{
	DM::GameObject::Update();
}





void SDV::TileObject::Render(HDC hdc) const
{
	DM::GameObject::Render(hdc);
}





void SDV::TileObject::Destroy()
{
	DM::GameObject::Destroy();
}





void SDV::TileObject::SetTopLeft(DM::Math::Vector2<FLOAT> topLeft)
{
	this->SetPosition(topLeft + this->GetOriginalSize()/2);
}
