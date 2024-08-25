#pragma once



namespace DM
{
	namespace Enums
	{
		enum class ComponentType;
		enum class LayerType;
		enum class TextureType;

		enum class KeyState;
	}
}





enum class DM::Enums::ComponentType
{
	Transform,
	Render,

	None
};





enum class DM::Enums::LayerType
{
	Background,
	Entity,

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