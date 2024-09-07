#include "DM_Collider_Box2D.h"

#include "DM_SceneManager.h"
#include "DM_Camera.h"
#include "DM_TransformComponent.h"
#include "DM_RigidBodyComponent.h"
#include "DM_GameObject.h"

#include "Test_Player.h"




DM::Collider_Box2D::Collider_Box2D(const GameObject* owner, const std::wstring& name)
	: ColliderComponent(owner, name, Enums::ColliderType::Box2D)
{
}





DM::Collider_Box2D::~Collider_Box2D()
{
}





void DM::Collider_Box2D::Initialize()
{
	ColliderComponent::Initialize();
}





void DM::Collider_Box2D::Update()
{
	ColliderComponent::Update();
}





void DM::Collider_Box2D::Render(HDC hdc)
{

	HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

	HPEN pen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);

	Math::Vector2<FLOAT> topLeft_relative = this->GetTopLeft()
		- SceneManager::GetActiveScene()->GetCamera()->GetTopLeft();


	Rectangle(hdc,
		static_cast<INT>(topLeft_relative.x),
		static_cast<INT>(topLeft_relative.y),
		static_cast<INT>(topLeft_relative.x + this->GetColliderSize().x),
		static_cast<INT>(topLeft_relative.y + this->GetColliderSize().y)
	);



	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(pen);

	return;
}