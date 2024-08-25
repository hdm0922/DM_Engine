#pragma once
#include "framework.h"





namespace DM
{
	struct Sprite;
}





struct DM::Sprite
{

	Sprite(
		const Math::Vector2<UINT>& topLeft	= { 0,0 },
		const Math::Vector2<UINT>& size		= { 0,0 },
		const Math::Vector2<UINT>& offset	= { 0,0 })
		: topLeft(topLeft), size(size), offset(offset) {};

	Math::Vector2<UINT> topLeft;
	Math::Vector2<UINT> size;
	Math::Vector2<UINT> offset;

};