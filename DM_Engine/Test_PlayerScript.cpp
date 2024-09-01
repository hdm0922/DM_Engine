#include "Test_PlayerScript.h"

#include "Test_Player.h"
#include "DM_Input.h"
#include "DM_RigidBodyComponent.h"
#include "Test_KeybindComponent.h"





Test::PlayerScript::PlayerScript(const DM::GameObject* owner, const std::wstring& name)
	: ScriptComponent(owner, name, static_cast<UINT>(State::None))
	, direction(Enums::Direction::Down)
{
}





Test::PlayerScript::~PlayerScript()
{
}





void Test::PlayerScript::Initialize()
{

	this->registerStateChangeConditions();
	this->registerStateEnterEvents();

	ScriptComponent::Initialize();
}





void Test::PlayerScript::Update()
{

	switch (static_cast<State>(this->GetCurrentState()))
	{
	case State::Idle	: this->onState_Idle();		break;
	case State::Walk	: this->onState_Walk();		break;
	case State::Run		: this->onState_Run();		break;
	case State::Fight	: this->onState_Fight();	break;
	}

	ScriptComponent::Update();
}





void Test::PlayerScript::registerStateChangeConditions()
{

	// On State : Idle
	this->stateChangeConditionMatrix[static_cast<UINT>(State::Idle)][static_cast<UINT>(State::Walk)]
		= std::bind(&PlayerScript::stateChangeCondition_Idle_to_Walk, this);

	this->stateChangeConditionMatrix[static_cast<UINT>(State::Idle)][static_cast<UINT>(State::Run)]
		= std::bind(&PlayerScript::stateChangeCondition_Idle_to_Run, this);

	// On State : Walk
	this->stateChangeConditionMatrix[static_cast<UINT>(State::Walk)][static_cast<UINT>(State::Idle)]
		= std::bind(&PlayerScript::stateChangeCondition_Walk_to_Idle, this);

	this->stateChangeConditionMatrix[static_cast<UINT>(State::Walk)][static_cast<UINT>(State::Run)]
		= std::bind(&PlayerScript::stateChangeCondition_Walk_to_Run, this);

	// On State : Run
	this->stateChangeConditionMatrix[static_cast<UINT>(State::Run)][static_cast<UINT>(State::Idle)]
		= std::bind(&PlayerScript::stateChangeCondition_Run_to_Idle, this);

	this->stateChangeConditionMatrix[static_cast<UINT>(State::Run)][static_cast<UINT>(State::Walk)]
		= std::bind(&PlayerScript::stateChangeCondition_Run_to_Walk, this);

	return;
}





void Test::PlayerScript::registerStateEnterEvents()
{

	this->stateEnterEvent[static_cast<UINT>(State::Idle)]
		= std::bind(&PlayerScript::stateEnterEvent_Idle, this);

	this->stateEnterEvent[static_cast<UINT>(State::Walk)]
		= std::bind(&PlayerScript::stateEnterEvent_Walk, this);

	this->stateEnterEvent[static_cast<UINT>(State::Run)]
		= std::bind(&PlayerScript::stateEnterEvent_Run, this);

	return;
}





void Test::PlayerScript::translate(FLOAT speed)
{

	DM::RigidBodyComponent* rigidBody = this->GetOwner()->GetComponent<DM::RigidBodyComponent>();
	KeybindComponent* keybind = this->GetOwner()->GetComponent<KeybindComponent>();

	INT dx = 0;
	INT dy = 0;

	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Up))		dy--;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Down))	dy++;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Right))	dx++;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Left))	dx--;

	rigidBody->SetVelocity(DM::Math::Vector2<FLOAT>(dx, dy) * speed);

	return;
}





void Test::PlayerScript::onState_Idle()
{

	DM::RigidBodyComponent* rigidBody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidBody->SetVelocity(0, 0);

}

void Test::PlayerScript::onState_Walk()
{
	this->translate(100.0f);

	return;
}

void Test::PlayerScript::onState_Run()
{
	this->translate(200.0f);

	return;
}

void Test::PlayerScript::onState_Fight()
{
}





BOOL Test::PlayerScript::stateChangeCondition_Idle_to_Walk()
{

	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();


	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Up))
	{
		this->direction = Enums::Direction::Up;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Left))
	{
		this->direction = Enums::Direction::Left;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Right))
	{
		this->direction = Enums::Direction::Right;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Down))
	{
		this->direction = Enums::Direction::Down;
		return true;
	}

	return false;
}





BOOL Test::PlayerScript::stateChangeCondition_Idle_to_Run()
{
	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	if (keybind->GetKeysPressed(KeybindComponent::Action::Run_Up))
	{
		this->direction = Enums::Direction::Up;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Run_Left))
	{
		this->direction = Enums::Direction::Left;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Run_Right))
	{
		this->direction = Enums::Direction::Right;
		return true;
	}

	if (keybind->GetKeysPressed(KeybindComponent::Action::Run_Down))
	{
		this->direction = Enums::Direction::Down;
		return true;
	}

	return false;
}





BOOL Test::PlayerScript::stateChangeCondition_Walk_to_Idle()
{

	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	switch (this->direction)
	{
	case Enums::Direction::Down:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Down);
	case Enums::Direction::Up:		return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Up);
	case Enums::Direction::Left:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Left);
	case Enums::Direction::Right:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Right);
	}

	return false;
}





BOOL Test::PlayerScript::stateChangeCondition_Walk_to_Run()
{

	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	return keybind->GetKeysPressed(KeybindComponent::Action::Switch_To_Run);
}





BOOL Test::PlayerScript::stateChangeCondition_Run_to_Idle()
{
	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	switch (this->direction)
	{
	case Enums::Direction::Down:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Down);
	case Enums::Direction::Up:		return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Up);
	case Enums::Direction::Left:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Left);
	case Enums::Direction::Right:	return keybind->GetKeysReleased(KeybindComponent::Action::Walk_Right);
	}

	return false;
}





BOOL Test::PlayerScript::stateChangeCondition_Run_to_Walk()
{
	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	return keybind->GetKeysReleased(KeybindComponent::Action::Switch_To_Run);
}





void Test::PlayerScript::stateEnterEvent_Idle()
{
	int a = 0;
}





void Test::PlayerScript::stateEnterEvent_Walk()
{

	switch (this->direction)
	{
	case Enums::Direction::Right:
		break;
	}

	return;
}





void Test::PlayerScript::stateEnterEvent_Run()
{
	int a = 0;
}
