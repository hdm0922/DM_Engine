#pragma once
#include "DM_GameObject.h"
#include "SDV_Framework.h"





namespace SDV
{
    class Tile;
}





namespace DM
{
	class Texture;
}





class SDV::Tile :
    public DM::GameObject
{

public:

	Tile(const DM::Math::Vector2<UINT>& index, const std::wstring& name = L"");
	virtual ~Tile();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Destroy() override;


public:

	void SetTexture(DM::Texture* texture);
	void SetTopLeft(DM::Math::Vector2<FLOAT> topLeft) { this->SetPosition(topLeft + this->GetSize() / 2.0f); }

	DM::Math::Vector2<UINT> GetTextureIndex() const { return this->textureIndex; }


private:

	DM::Math::Vector2<UINT> textureIndex;

};

