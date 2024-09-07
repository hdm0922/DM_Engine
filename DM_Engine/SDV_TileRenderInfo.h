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


	// texture 내의 위치 인덱스
	DM::Math::Vector2<UINT> textureIndex;

	// topLeft의 인덱스 = (0, 0)에 대한 현재 타일의 인덱스
	DM::Math::Vector2<UINT> tileIndex_relative;
};