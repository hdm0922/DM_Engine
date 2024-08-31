#include "Test_Player.h"

#include "Test_PlayerScript.h"
#include "Test_KeybindComponent.h"

#include "DM_Input.h"


Test::Player::Player(const std::wstring& name)
	: TestObject(name)
{
	this->AddComponent<PlayerScript>();
	this->AddComponent<KeybindComponent>();
}





Test::Player::~Player()
{
}





void Test::Player::Initialize()
{
	TestObject::Initialize();
}





void Test::Player::Update()
{
	TestObject::Update();
}