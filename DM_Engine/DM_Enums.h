#pragma once



namespace DM
{
	namespace Enums
	{
		enum class keyState;
	}
}



enum class DM::Enums::keyState
{
	Pressed,
	Hold,
	Up,

	None
};