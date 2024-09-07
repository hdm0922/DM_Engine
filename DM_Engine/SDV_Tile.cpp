#include "SDV_Tile.h"

#include "DM_ResourceManager.h"
#include "DM_SpriteRenderer.h"
#include "DM_Sprite.h"

#include "SDV_TileObject.h"





SDV::Tile::Tile(const DM::Math::Vector2<UINT>& index, const TileObject* owner, const std::wstring& name)
	: DM::GameObject(name)
	, textureIndex(index)
	, owner(owner)
{

	this->SetOriginalSize(SDV_TILE_SIZE);

	this->AddComponent<DM::SpriteRenderer>();
	DM::SpriteRenderer* spriteRenderer = this->GetComponent<DM::SpriteRenderer>();
	spriteRenderer->SetSprite(new DM::Sprite(
		{index.x * SDV_TILE_SIZE.x, index.y * SDV_TILE_SIZE.y },
		SDV_TILE_SIZE
	));

	spriteRenderer->SetTexture(DM::ResourceManager::GetResource<DM::Texture>(SDV_NAME_TEXTURE_SPRING_OUTDOOR));
}





SDV::Tile::~Tile()
{
}





void SDV::Tile::Initialize()
{
}





void SDV::Tile::Update()
{
}





void SDV::Tile::Destroy()
{
}





void SDV::Tile::SetTexture(DM::Texture* texture)
{
	this->GetComponent<DM::SpriteRenderer>()->SetTexture(texture);
}





DM::Math::Vector2<FLOAT> SDV::Tile::GetPosition() const
{
	return (this->owner ? this->owner->GetPosition() : DM::Math::Vector2<FLOAT>(0.0f, 0.0f))
		+ this->GetPosition_Relative();
}
