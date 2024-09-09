#include "SDV_Player.h"

#include "SDV_KeybindComponent.h"
#include "SDV_PlayerScript.h"
#include "DM_Input.h"





SDV::Player::Player(const std::wstring& name)
	: Pawn(name)
{
	this->AddComponent<SDV::PlayerScript>();
	this->AddComponent<SDV::KeybindComponent>();

	this->bindKeys();
}





SDV::Player::~Player()
{
}





void SDV::Player::Initialize()
{
	Pawn::Initialize();
}





void SDV::Player::Update()
{
	Pawn::Update();
}





void SDV::Player::bindKeys()
{

	KeybindComponent* keybind = this->GetComponent<KeybindComponent>();

	keybind->SetKeys(KeybindComponent::Action::Walk_Down,		{ 'S' });
	keybind->SetKeys(KeybindComponent::Action::Walk_Left,		{ 'A' });
	keybind->SetKeys(KeybindComponent::Action::Walk_Right,		{ 'D' });
	keybind->SetKeys(KeybindComponent::Action::Walk_Up,			{ 'W' });

	keybind->SetKeys(KeybindComponent::Action::Run_Down,		{ VK_SHIFT, 'S' });
	keybind->SetKeys(KeybindComponent::Action::Run_Left,		{ VK_SHIFT, 'A' });
	keybind->SetKeys(KeybindComponent::Action::Run_Right,		{ VK_SHIFT, 'D' });
	keybind->SetKeys(KeybindComponent::Action::Run_Up,			{ VK_SHIFT, 'W' });

	keybind->SetKeys(KeybindComponent::Action::Switch_To_Run,	{ VK_SHIFT });

	return;
}
