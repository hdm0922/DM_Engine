#pragma once
#include "DM_GameObject.h"
#include "SDV_Framework.h"





namespace SDV
{
    class TileObject;
}





namespace DM
{
	struct Sprite;
}





class SDV::TileObject :
    public DM::GameObject
{

public:

	TileObject(const DM::Sprite* topLeftSprite, const std::wstring& name = L"");
	virtual ~TileObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc) const;
	virtual void Destroy();


public:

	const DM::Sprite* GetSprite() const { return this->topLeftSprite; }

	// TileObject가 그려지는데 사용되는 타일들의 개수
	const DM::Math::Vector2<UINT> GetRenderTiles() const { return this->renderTiles; }


private:

	const DM::Sprite* topLeftSprite;
	const DM::Math::Vector2<UINT> renderTiles;


};

