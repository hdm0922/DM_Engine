#include "DM_Collider_Box2D.h"

#include "DM_TransformComponent.h"
#include "DM_GameObject.h"





DM::Collider_Box2D::Collider_Box2D(const GameObject* owner, const std::wstring& name)
	: ColliderComponent(owner, name, Enums::ColliderType::Box2D)
{
	size = { 100,100 };
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



	Math::Vector2<FLOAT> position =
		this->GetOwner()->GetComponent<TransformComponent>()
		->GetPosition();

	Rectangle(hdc,
		position.x,
		position.y,
		position.x + size.x,
		position.y + size.y
	);




	SelectObject(hdc, oldBrush);

	SelectObject(hdc, oldPen);
	DeleteObject(pen);

	return;
}
