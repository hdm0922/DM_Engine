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

	this->keysets[static_cast<UINT>(Action::Walk_Down)] = { 'S' };
	this->keysets[static_cast<UINT>(Action::Walk_Left)] = { 'A' };
	this->keysets[static_cast<UINT>(Action::Walk_Right)] = { 'D' };
	this->keysets[static_cast<UINT>(Action::Walk_Up)] = { 'W' };

	this->keysets[static_cast<UINT>(Action::Run_Down)] = { VK_SHIFT, 'S' };
	this->keysets[static_cast<UINT>(Action::Run_Left)] = { VK_SHIFT, 'A' };
	this->keysets[static_cast<UINT>(Action::Run_Right)] = { VK_SHIFT, 'D' };
	this->keysets[static_cast<UINT>(Action::Run_Up)] = { VK_SHIFT, 'W' };

	this->keysets[static_cast<UINT>(Action::Switch_To_Run)] = { VK_SHIFT };

	return;
}





void SDV::KeybindComponent::Update()
{
}





BOOL SDV::KeybindComponent::GetKeysPressed(Action action) const
{

	UINT actionIdx = static_cast<UINT>(action);

	for (INT key : this->keysets[actionIdx])
	{
		if (DM::Input::GetKeyPressed(key) ||
			DM::Input::GetKeyHold(key)) continue;

		return false;
	}

	return true;
}





BOOL SDV::KeybindComponent::GetKeysReleased(Action action) const
{

	UINT actionIdx = static_cast<UINT>(action);

	for (INT key : this->keysets[actionIdx])
	{
		if (DM::Input::GetKeyReleased(key)) return true;
	}

	return false;
}
