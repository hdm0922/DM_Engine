#include "Test_KeybindComponent.h"

#include "Test_PlayerScript.h"
#include "DM_GameObject.h"
#include "DM_Input.h"





Test::KeybindComponent::KeybindComponent(const DM::GameObject* owner, const std::wstring& name)
	: DM::Component(owner, name, DM::Enums::ComponentType::None)
	, functions({nullptr})
	, keybindInfo({})
{
	this->functions.resize(20);
	this->keybindInfo.resize(20);
}





Test::KeybindComponent::~KeybindComponent()
{
	for (auto& iter : this->keybindInfo)
	{
		if (iter.first)
		{
			delete iter.first;
			iter.first = nullptr;
		}

		if (iter.second)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}





void Test::KeybindComponent::Initialize()
{
	this->initialize_functions();
	this->initialize_keybindInfo();
}





void Test::KeybindComponent::Update()
{
	for (INT iter = 1; iter < 20; iter++)
	{
		this->listen_keyEvent(iter);
	}
}





void Test::KeybindComponent::ChangeKeybind_FirstSlot(INT idx, std::vector<INT>* keyset)
{

	// 동일한 키셋을 이미 사용중인가?
	for (INT iter = 1; iter < 20; iter++)
	{

		if (this->keybindInfo[iter].first &&
		(  *this->keybindInfo[iter].first == *keyset))
		{
			return; // 에러창 띄우기
		}

		if (this->keybindInfo[iter].second &&
		(  *this->keybindInfo[iter].second == *keyset))
		{
			return; // 에러창 띄우기
		}

	}

	if (this->keybindInfo[idx].first) { delete this->keybindInfo[idx].first; }
	this->keybindInfo[idx].first = keyset;

	return;
}





void Test::KeybindComponent::ChangeKeybind_SecondSlot(INT idx, std::vector<INT>* keyset)
{
	// 동일한 키셋을 이미 사용중인가?
	for (INT iter = 1; iter < 20; iter++)
	{

		if (this->keybindInfo[iter].first &&
			(*this->keybindInfo[iter].first == *keyset))
		{
			return; // 에러창 띄우기
		}

		if (this->keybindInfo[iter].second &&
			(*this->keybindInfo[iter].second == *keyset))
		{
			return; // 에러창 띄우기
		}

	}

	if (this->keybindInfo[idx].second) { delete this->keybindInfo[idx].second; }
	this->keybindInfo[idx].second = keyset;

	return;

}





void Test::KeybindComponent::initialize_functions()
{

	PlayerScript* script = this->GetOwner()->GetComponent<PlayerScript>();

	this->functions[1] = std::bind(&PlayerScript::Walk_Right,	script);
	this->functions[2] = std::bind(&PlayerScript::Walk_Down,	script);
	this->functions[3] = std::bind(&PlayerScript::Walk_Left,	script);
	this->functions[4] = std::bind(&PlayerScript::Walk_Up,		script);

	this->functions[5] = std::bind(&PlayerScript::Run_Right,	script);
	this->functions[6] = std::bind(&PlayerScript::Run_Down,		script);
	this->functions[7] = std::bind(&PlayerScript::Run_Left,		script);
	this->functions[8] = std::bind(&PlayerScript::Run_Up,		script);

	return;
}





void Test::KeybindComponent::initialize_keybindInfo()
{

	PlayerScript* script = this->GetOwner()->GetComponent<PlayerScript>();

	this->keybindInfo[1].first = new std::vector<INT>({ 'D' });
	this->keybindInfo[2].first = new std::vector<INT>({ 'S' });
	this->keybindInfo[3].first = new std::vector<INT>({ 'A' });
	this->keybindInfo[4].first = new std::vector<INT>({ 'W' });

	this->keybindInfo[5].first = new std::vector<INT>({ VK_SHIFT, 'D' });
	this->keybindInfo[6].first = new std::vector<INT>({ VK_SHIFT, 'S' });
	this->keybindInfo[7].first = new std::vector<INT>({ VK_SHIFT, 'A' });
	this->keybindInfo[8].first = new std::vector<INT>({ VK_SHIFT, 'W' });

	return;
}





void Test::KeybindComponent::listen_keyEvent(INT idx)
{

	BOOL allKeysPressed;

	if (this->keybindInfo[idx].first)
	{
		allKeysPressed = true;

		for (INT key : *this->keybindInfo[idx].first)
		{
			if (DM::Input::GetKeyPressed(key) ||
				DM::Input::GetKeyHold(key)) continue;
			allKeysPressed = false;
		}

		if (allKeysPressed) this->functions[idx]();
	}



	if (this->keybindInfo[idx].second)
	{
		allKeysPressed = true;

		for (INT key : *this->keybindInfo[idx].second)
		{
			if (DM::Input::GetKeyPressed(key) ||
				DM::Input::GetKeyHold(key)) continue;
			allKeysPressed = false;
		}

		if (allKeysPressed) this->functions[idx]();
	}



	return;
}
