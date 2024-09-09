#include "DM_Camera.h"

#include "DM_Input.h"





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
	if (this->renderTarget) 
	{
		this->SetPosition(this->renderTarget->GetPosition());
		return;
	} 

	const FLOAT DELTA = 0.7f;
	if (Input::GetKeysPressed({ VK_UP }))		this->SetPosition(this->GetPosition() + Math::Vector2<FLOAT>(0.0f, -DELTA));
	if (Input::GetKeysPressed({ VK_DOWN }))		this->SetPosition(this->GetPosition() + Math::Vector2<FLOAT>(0.0f, DELTA));
	if (Input::GetKeysPressed({ VK_LEFT }))		this->SetPosition(this->GetPosition() + Math::Vector2<FLOAT>(-DELTA, 0.0f));
	if (Input::GetKeysPressed({ VK_RIGHT }))	this->SetPosition(this->GetPosition() + Math::Vector2<FLOAT>(DELTA, 0.0f));
}





DM::Math::Vector2<FLOAT> DM::Camera::GetSize() const
{
	return Math::Vector2<FLOAT>(
		static_cast<FLOAT>(Application::GetMainWindow()->GetSize().x),
		static_cast<FLOAT>(Application::GetMainWindow()->GetSize().y)
	);
}
