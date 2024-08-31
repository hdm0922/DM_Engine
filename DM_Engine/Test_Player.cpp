#include "Test_Player.h"

#include "Test_PlayerScript.h"

#include "DM_Input.h"


Test::Player::Player(const std::wstring& name)
	: TestObject(name)
	, keyEvents({})
{
	this->AddComponent<PlayerScript>();
}





Test::Player::~Player()
{
}





void Test::Player::Initialize()
{
	TestObject::Initialize();

	this->registerKeyEvents();
}





void Test::Player::Update()
{

	for (auto& iter : this->keyEvents)
	{
		if (!DM::Input::GetKeyPressed(iter.first)) continue;

		iter.second();
	}

	TestObject::Update();
}





void Test::Player::registerKeyEvents()
{

	PlayerScript* script = this->GetComponent<PlayerScript>();
	assert(script);

	std::function<void()> eventFunction;

	eventFunction = std::bind(&PlayerScript::MoveUp, script);
	this->keyEvents.insert({ 'W', eventFunction });

	eventFunction = std::bind(&PlayerScript::MoveDown, script);
	this->keyEvents.insert({ 'S', eventFunction });

	eventFunction = std::bind(&PlayerScript::MoveRight, script);
	this->keyEvents.insert({ 'D', eventFunction });

	eventFunction = std::bind(&PlayerScript::MoveLeft, script);
	this->keyEvents.insert({ 'A', eventFunction });

	return;
}
