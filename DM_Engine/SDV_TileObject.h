#pragma once
#include "DM_GameObject.h"

#include "DM_Container2D.h"
#include "SDV_Framework.h"





namespace SDV
{
    class TileObject;
	class Tile;
}





namespace DM
{
	struct Sprite;
}





class SDV::TileObject :
    public DM::GameObject
{

public:

	TileObject(const DM::Math::Vector2<UINT>& containerSize, const std::wstring& name = L"");
	virtual ~TileObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) const override;
	virtual void Destroy() override;

	void SetTile(Tile* tile, const DM::Math::Vector2<UINT>& index);
	DM::Container2D<Tile> tilesContainer;

private:

	


};

