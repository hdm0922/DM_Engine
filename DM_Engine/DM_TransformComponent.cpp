#include "DM_TransformComponent.h"





DM::TransformComponent::TransformComponent(const GameObject* owner, const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::Transform)
	, position(0.0f, 0.0f)
	, scale(0.0f, 0.0f)
	, rotation(0.0f)
{
}





DM::TransformComponent::~TransformComponent()
{
}





void DM::TransformComponent::Initialize()
{
}





void DM::TransformComponent::Update()
{
}