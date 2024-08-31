#include "Test_PlayerScript.h"

#include "Test_Player.h"
#include "DM_Input.h"

Test::PlayerScript::PlayerScript(const DM::GameObject* owner, const std::wstring& name)
	: ScriptComponent(owner, name)
	, keyEvents({})
{
}

Test::PlayerScript::~PlayerScript()
{
}

void Test::PlayerScript::Initialize()
{
	this->registerKeyEvents();
}

void Test::PlayerScript::Update()
{
	for (auto& iter : this->keyEvents)
	{
		if (!DM::Input::GetKeyPressed(iter.first)) continue;

		iter.second();
	}
}





void Test::PlayerScript::registerKeyEvents()
{

	std::function<void()> eventFunction;

	eventFunction = std::bind(&PlayerScript::moveUp, this);
	this->keyEvents.insert({ 'W', eventFunction });

	eventFunction = std::bind(&PlayerScript::moveDown, this);
	this->keyEvents.insert({ 'S', eventFunction });

	eventFunction = std::bind(&PlayerScript::moveRight, this);
	this->keyEvents.insert({ 'D', eventFunction });

	eventFunction = std::bind(&PlayerScript::moveLeft, this);
	this->keyEvents.insert({ 'A', eventFunction });

	return;
}





void Test::PlayerScript::moveRight()
{
}

void Test::PlayerScript::moveLeft()
{
}

void Test::PlayerScript::moveDown()
{
	int a = 0;
}

void Test::PlayerScript::moveUp()
{
	int a = 0;

}
