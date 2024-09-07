#include "SDV_TileObject.h"

#include "SDV_Tile.h"





SDV::TileObject::TileObject(const DM::Math::Vector2<UINT>& containerSize, const std::wstring& name)
	: DM::GameObject(name)
	, tilesContainer(containerSize)
{
	this->SetOriginalSize(
		static_cast<FLOAT>(containerSize.x * SDV_TILE_SIZE.x),
		static_cast<FLOAT>(containerSize.y * SDV_TILE_SIZE.y)
	);
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

	DM::Math::Vector2<UINT> containerSize = this->tilesContainer.GetContainerSize();

	for (UINT y = 0; y < containerSize.y; y++)
		for (UINT x = 0; x < containerSize.x; x++)
		{
			if (!this->tilesContainer.GetItem(x, y)) continue;
			this->tilesContainer.GetItem(x, y)->Render(hdc);
		}
			

	DM::GameObject::Render(hdc);
}





void SDV::TileObject::Destroy()
{
	DM::GameObject::Destroy();
}





void SDV::TileObject::SetTile(Tile* tile, const DM::Math::Vector2<UINT>& index)
{

	DM::Math::Vector2<FLOAT> tilePosition_relative = { 
		static_cast<FLOAT>(index.x * SDV_TILE_SIZE.x),
		static_cast<FLOAT>(index.y * SDV_TILE_SIZE.y)
	};

	DM::Math::Vector2<FLOAT> topLeft_tile = tile->GetOwner()->GetTopLeft() + tilePosition_relative;
	DM::Math::Vector2<FLOAT> position_tile = topLeft_tile + tile->GetOriginalSize() / 2.0f;

	tile->SetPosition(position_tile - tile->GetOwner()->GetPosition());
	this->tilesContainer.SetItem(index, tile);
	return;
}
