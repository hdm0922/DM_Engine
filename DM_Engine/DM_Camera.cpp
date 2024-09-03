#include "DM_Camera.h"

DM::Camera::Camera(const std::wstring& name)
	: GameObject(name)
	, renderTarget(nullptr)
{
}





DM::Camera::~Camera()
{
}





void DM::Camera::Initialize()
{
}





void DM::Camera::Update()
{
	if (!this->renderTarget) return;
	this->SetPosition(this->renderTarget->GetPosition());
}





DM::Math::Vector2<FLOAT> DM::Camera::GetSize() const
{
	return Math::Vector2<FLOAT>(
		static_cast<FLOAT>(Application::GetMainWindow()->GetSize().x),
		static_cast<FLOAT>(Application::GetMainWindow()->GetSize().y)
	);
}
