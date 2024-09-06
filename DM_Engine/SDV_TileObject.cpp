#include "SDV_TileObject.h"

#include "DM_Sprite.h"





SDV::TileObject::TileObject(
	const DM::Sprite* topLeftSprite,
	const std::wstring& name)
	: DM::GameObject(name)
	, topLeftSprite(topLeftSprite)
	, renderTiles({ topLeftSprite->size.x / SDV_TILE_SIZE.x, topLeftSprite->size.y / SDV_TILE_SIZE.y })
{
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
