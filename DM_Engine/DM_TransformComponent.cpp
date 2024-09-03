#include "DM_TransformComponent.h"

#include "DM_SceneManager.h"





DM::TransformComponent::TransformComponent(const GameObject* owner, const std::wstring& name)
	: Component(owner, name, Enums::ComponentType::Transform)
	, position(0.0f, 0.0f)
	, scale(1.0f, 1.0f)
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





DM::Math::Vector2<FLOAT> DM::TransformComponent::GetScale() const
{
	return Math::Vector2<FLOAT>(
		SceneManager::GetSceneScale().x * this->scale.x,
		SceneManager::GetSceneScale().y * this->scale.y
	);
}
