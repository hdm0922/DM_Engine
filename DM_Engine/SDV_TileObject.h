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
	TileObject(const TileObject& tileObject) : TileObject(tileObject.topLeftSprite, tileObject.GetName()) {}
	virtual ~TileObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) const override;
	virtual void Destroy() override;

	void SetTopLeft(DM::Math::Vector2<FLOAT> topLeft);


public:

	const DM::Sprite* GetSprite() const { return this->topLeftSprite; }


private:

	const DM::Sprite* topLeftSprite;


};

