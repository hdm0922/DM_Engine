#pragma once



namespace DM
{
	namespace Enums
	{
		enum class ComponentType;

		enum class KeyState;
	}
}



enum class DM::Enums::KeyState
{
	Pressed,
	Hold,
	Up,

	None
};