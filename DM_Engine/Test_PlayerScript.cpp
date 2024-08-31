#include "Test_PlayerScript.h"

#include "Test_Player.h"
#include "DM_Input.h"





Test::PlayerScript::PlayerScript(const DM::GameObject* owner, const std::wstring& name)
	: ScriptComponent(owner, name)
	, state(State::Idle)
{
}





Test::PlayerScript::~PlayerScript()
{
}





void Test::PlayerScript::Initialize()
{
	ScriptComponent::Initialize();
}





void Test::PlayerScript::Update()
{

	switch (this->GetState())
	{
	case State::Idle	: this->onState_Idle();		break;
	case State::Walk	: this->onState_Walk();		break;
	case State::Run		: this->onState_Run();		break;
	case State::Fight	: this->onState_Fight();	break;
	}

	ScriptComponent::Update();
}





void Test::PlayerScript::Walk_Right()
{
}

void Test::PlayerScript::Walk_Left()
{
}

void Test::PlayerScript::Walk_Down()
{
	int a = 0;
}

void Test::PlayerScript::Walk_Up()
{
}

void Test::PlayerScript::Run_Right()
{
}

void Test::PlayerScript::Run_Left()
{
}

void Test::PlayerScript::Run_Down()
{
	int a = 0;
}

void Test::PlayerScript::Run_Up()
{
}





void Test::PlayerScript::onState_Idle()
{
}

void Test::PlayerScript::onState_Walk()
{
}

void Test::PlayerScript::onState_Run()
{
}

void Test::PlayerScript::onState_Fight()
{
}