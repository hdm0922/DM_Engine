#pragma once



namespace DM
{
	namespace Enums
	{
		enum class ComponentType;
		enum class TextureType;

		enum class KeyState;
	}
}





enum class DM::Enums::ComponentType
{
	Transform,

	None
};





enum class DM::Enums::TextureType
{
	bmp,
	png,

	None
};





enum class DM::Enums::KeyState
{
	Pressed,
	Hold,
	Up,

	None
};