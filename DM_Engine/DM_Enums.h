#pragma once



namespace DM
{
	namespace Enums
	{
		enum class ComponentType;
		enum class LayerType;
		enum class TextureType;
		enum class ColliderType;

		enum class KeyState;
	}
}





enum class DM::Enums::ComponentType
{
	Transform,
	Collider,
	RigidBody,
	State,
	Script,
	Render,
	Audio,

	None
};





enum class DM::Enums::LayerType
{
	Background,
	Tile,
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
	Released,

	None
};






enum class DM::Enums::ColliderType
{
	Box2D,

	None
};