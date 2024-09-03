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
