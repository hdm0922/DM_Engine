#include "Test_PlayerScript.h"

#include "Test_Player.h"
#include "DM_Input.h"
#include "DM_RigidBodyComponent.h"





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





void Test::PlayerScript::Stop()
{
}





void Test::PlayerScript::Walk_Right()
{
	DM::RigidBodyComponent* rigidbody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidbody->SetVelocity(100.0f, 0.0f);
}

void Test::PlayerScript::Walk_Left()
{
	DM::RigidBodyComponent* rigidbody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidbody->SetVelocity(-100.0f, 0.0f);
}

void Test::PlayerScript::Walk_Down()
{
	DM::RigidBodyComponent* rigidbody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidbody->SetVelocity(0.0f, 100.0f);
}

void Test::PlayerScript::Walk_Up()
{
	DM::RigidBodyComponent* rigidbody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidbody->SetVelocity(0.0f, -100.0f);
}





void Test::PlayerScript::Run_Right()
{
	this->GetOwner()->SetPosition(
		this->GetOwner()->GetPosition() +
		DM::Math::Vector2<FLOAT>(0.05f, 0.0f)
	);
}

void Test::PlayerScript::Run_Left()
{
	this->GetOwner()->SetPosition(
		this->GetOwner()->GetPosition() +
		DM::Math::Vector2<FLOAT>(-0.05f, 0.0f)
	);
}

void Test::PlayerScript::Run_Down()
{
	this->GetOwner()->SetPosition(
		this->GetOwner()->GetPosition() +
		DM::Math::Vector2<FLOAT>(0.0f, 0.05f)
	);
}

void Test::PlayerScript::Run_Up()
{
	this->GetOwner()->SetPosition(
		this->GetOwner()->GetPosition() +
		DM::Math::Vector2<FLOAT>(0.0f, -0.05f)
	);
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