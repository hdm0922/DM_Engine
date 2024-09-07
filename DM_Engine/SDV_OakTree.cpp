#include "SDV_OakTree.h"

#include "DM_Collider_Box2D.h"
#include "SDV_Tile.h"





SDV::OakTree::OakTree(const std::wstring& name)
	: Tree({3,6}, name)
{
	this->SetOriginalSize(
		static_cast<FLOAT>(3 * SDV_TILE_SIZE.x),
		static_cast<FLOAT>(6 * SDV_TILE_SIZE.y)
	);

	//this->AddComponent<DM::Collider_Box2D>();
	//DM::Collider_Box2D* collider = this->GetComponent<DM::Collider_Box2D>();
	//collider->SetColliderSize(SDV_TILE_SIZE);


	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(0, 0), this), { 0,0 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(0, 1), this), { 0,1 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(0, 2), this), { 0,2 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(0, 3), this), { 0,3 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(0, 5), this), { 0,5 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 0), this), { 1,0 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 1), this), { 1,1 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 2), this), { 1,2 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 3), this), { 1,3 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 4), this), { 1,4 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(1, 5), this), { 1,5 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(2, 0), this), { 2,0 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(2, 1), this), { 2,1 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(2, 2), this), { 2,2 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(2, 3), this), { 2,3 });
	this->SetTile(new SDV::Tile(DM::Math::Vector2<UINT>(2, 4), this), { 2,4 });
}





SDV::OakTree::~OakTree()
{
}
