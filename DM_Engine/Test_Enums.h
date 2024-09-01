#pragma once

namespace Test
{
	namespace Enums
	{
		enum class Direction;
	}
}

enum class Test::Enums::Direction
{
	Right,
	Left,
	Down,
	Up,

	None
};