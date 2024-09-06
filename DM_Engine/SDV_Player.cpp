#include "SDV_Player.h"

#include "SDV_KeybindComponent.h"
#include "SDV_PlayerScript.h"
#include "DM_Input.h"





SDV::Player::Player(const std::wstring& name)
	: Pawn(name)
{
	this->AddComponent<SDV::PlayerScript>();
	this->AddComponent<SDV::KeybindComponent>();
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