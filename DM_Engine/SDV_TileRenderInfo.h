#pragma once
#include "SDV_Framework.h"





namespace SDV
{
	struct TileRenderInfo;
}





struct SDV::TileRenderInfo
{

	TileRenderInfo(const DM::Math::Vector2<UINT>& textureIndex, const DM::Math::Vector2<UINT>& tileIndex_relative) :
		textureIndex(textureIndex), tileIndex_relative(tileIndex_relative) {}


	// texture ���� ��ġ �ε���
	DM::Math::Vector2<UINT> textureIndex;

	// topLeft�� �ε��� = (0, 0)�� ���� ���� Ÿ���� �ε���
	DM::Math::Vector2<UINT> tileIndex_relative;
};