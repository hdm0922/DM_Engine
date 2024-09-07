#pragma once
#include "SDV_TileObject.h"





namespace SDV
{
    class Tree;
}





class SDV::Tree :
    public TileObject
{

public:

	Tree(const DM::Math::Vector2<UINT>& containerSize, const std::wstring& name = L"");
	virtual ~Tree() override;


};

