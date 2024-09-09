#include "SDV_KeybindComponent.h"

#include "DM_Input.h"





SDV::KeybindComponent::KeybindComponent(const DM::GameObject* owner, const std::wstring& name)
	: DM::Component(owner, name, DM::Enums::ComponentType::None)
	, keysets(nullptr)
{
	this->keysets = new std::vector<INT>[static_cast<UINT>(Action::None)];
}





SDV::KeybindComponent::~KeybindComponent()
{
	delete[] this->keysets;
	this->keysets = nullptr;
}





void SDV::KeybindComponent::Initialize()
{



	return;
}





void SDV::KeybindComponent::Update()
{
}





BOOL SDV::KeybindComponent::GetKeysPressed(Action action) const
{
	UINT actionIdx = static_cast<UINT>(action);
	return DM::Input::GetKeysPressed(this->keysets[actionIdx]);
}





BOOL SDV::KeybindComponent::GetKeysReleased(Action action) const
{
	UINT actionIdx = static_cast<UINT>(action);
	return DM::Input::GetKeysReleased(this->keysets[actionIdx]);
}
