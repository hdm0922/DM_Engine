#include "SDV_PlayerScript.h"

#include "SDV_Player.h"
#include "DM_Input.h"
#include "DM_RigidBodyComponent.h"
#include "DM_AnimationRenderer.h"
#include "SDV_KeybindComponent.h"
#include "SDV_GameStateComponent.h"





SDV::PlayerScript::PlayerScript(const DM::GameObject* owner, const std::wstring& name)
	: ScriptComponent(owner, name, static_cast<UINT>(State::None))
	, direction(Enums::Direction::Down)
{
}





SDV::PlayerScript::~PlayerScript()
{
}





void SDV::PlayerScript::Initialize()
{

	this->stateEnterEvent_Idle();

	this->registerStateChangeConditions();
	this->registerStateEnterEvents();

	ScriptComponent::Initialize();
}





void SDV::PlayerScript::Update()
{

	switch (static_cast<State>(this->GetCurrentState()))
	{
	case State::Idle: this->onState_Idle();		break;
	case State::Walk: this->onState_Walk();		break;
	case State::Run: this->onState_Run();		break;
	case State::Fight: this->onState_Fight();	break;
	}

	ScriptComponent::Update();
}





void SDV::PlayerScript::CollisionEvent_Enter(const DM::GameObject* other)
{
}





void SDV::PlayerScript::CollisionEvent_Collide(const DM::GameObject* other)
{

	GameStateComponent* gameState_other = other->GetComponent<GameStateComponent>();
	if (gameState_other && gameState_other->BlocksPlayer()) this->blockedByGameObject(other);

	return;
}





void SDV::PlayerScript::CollisionEvent_Exit(const DM::GameObject* other)
{
}





void SDV::PlayerScript::registerStateChangeConditions()
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





void SDV::PlayerScript::registerStateEnterEvents()
{

	this->stateEnterEvent[static_cast<UINT>(State::Idle)]
		= std::bind(&PlayerScript::stateEnterEvent_Idle, this);

	this->stateEnterEvent[static_cast<UINT>(State::Walk)]
		= std::bind(&PlayerScript::stateEnterEvent_Walk, this);

	this->stateEnterEvent[static_cast<UINT>(State::Run)]
		= std::bind(&PlayerScript::stateEnterEvent_Run, this);

	return;
}





void SDV::PlayerScript::translate(FLOAT speed)
{

	DM::RigidBodyComponent* rigidBody = this->GetOwner()->GetComponent<DM::RigidBodyComponent>();
	KeybindComponent* keybind = this->GetOwner()->GetComponent<KeybindComponent>();

	INT dx = 0;
	INT dy = 0;

	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Up))		dy--;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Down))	dy++;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Right))	dx++;
	if (keybind->GetKeysPressed(KeybindComponent::Action::Walk_Left))	dx--;

	rigidBody->SetVelocity(DM::Math::Vector2<FLOAT>(
		static_cast<FLOAT>(dx), static_cast<FLOAT>(dy)) * speed);

	return;
}





void SDV::PlayerScript::onState_Idle()
{

	DM::RigidBodyComponent* rigidBody =
		this->GetOwner()->GetComponent<DM::RigidBodyComponent>();

	rigidBody->SetVelocity(0, 0);

}

void SDV::PlayerScript::onState_Walk()
{
	this->translate(100.0f);

	return;
}

void SDV::PlayerScript::onState_Run()
{
	this->translate(200.0f);

	return;
}

void SDV::PlayerScript::onState_Fight()
{
}





BOOL SDV::PlayerScript::stateChangeCondition_Idle_to_Walk()
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





BOOL SDV::PlayerScript::stateChangeCondition_Idle_to_Run()
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





BOOL SDV::PlayerScript::stateChangeCondition_Walk_to_Idle()
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





BOOL SDV::PlayerScript::stateChangeCondition_Walk_to_Run()
{

	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	return keybind->GetKeysPressed(KeybindComponent::Action::Switch_To_Run);
}





BOOL SDV::PlayerScript::stateChangeCondition_Run_to_Idle()
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





BOOL SDV::PlayerScript::stateChangeCondition_Run_to_Walk()
{
	KeybindComponent* keybind =
		this->GetOwner()->GetComponent<KeybindComponent>();

	return keybind->GetKeysReleased(KeybindComponent::Action::Switch_To_Run);
}





void SDV::PlayerScript::stateEnterEvent_Idle()
{

	DM::AnimationRenderer* animationRenderer = this->GetOwner()->GetComponent<DM::AnimationRenderer>();

	switch (this->direction)
	{
	case Enums::Direction::Right:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_IDLE_RIGHT, false); break;
	case Enums::Direction::Left:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_IDLE_LEFT, false); break;
	case Enums::Direction::Down:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_IDLE_DOWN, false); break;
	case Enums::Direction::Up:		animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_IDLE_UP, false); break;
	}

	return;
}





void SDV::PlayerScript::stateEnterEvent_Walk()
{

	DM::AnimationRenderer* animationRenderer = this->GetOwner()->GetComponent<DM::AnimationRenderer>();

	switch (this->direction)
	{
	case Enums::Direction::Right:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_RIGHT, true); break;
	case Enums::Direction::Left:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_LEFT, true); break;
	case Enums::Direction::Down:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_DOWN, true); break;
	case Enums::Direction::Up:		animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_UP, true); break;
	}

	return;
}





void SDV::PlayerScript::stateEnterEvent_Run()
{

	DM::AnimationRenderer* animationRenderer = this->GetOwner()->GetComponent<DM::AnimationRenderer>();

	switch (this->direction)
	{
	case Enums::Direction::Right:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_RIGHT, true); break;
	case Enums::Direction::Left:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_LEFT, true); break;
	case Enums::Direction::Down:	animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_DOWN, true); break;
	case Enums::Direction::Up:		animationRenderer->Play(SDV_NAME_ANIMATION_PLAYER_MOVE_UP, true); break;
	}

	return;
}





void SDV::PlayerScript::blockedByGameObject(const DM::GameObject* object)
{

	DM::Math::Vector2<FLOAT> overlap;

	overlap.x = std::min(this->GetOwner()->GetBottomRight().x, object->GetBottomRight().x) - std::max(this->GetOwner()->GetTopLeft().x, object->GetTopLeft().x);
	overlap.y = std::min(this->GetOwner()->GetBottomRight().y, object->GetBottomRight().y) - std::max(this->GetOwner()->GetTopLeft().y, object->GetTopLeft().y);

	DM::Math::Vector2<FLOAT> delta = { 0, 0 };
	if (overlap.x < overlap.y)	delta.x = (this->GetOwner()->GetTopLeft().x > object->GetTopLeft().x) ? overlap.x : -overlap.x;
	else						delta.y = (this->GetOwner()->GetTopLeft().y > object->GetTopLeft().y) ? overlap.y : -overlap.y;

	this->GetOwner()->SetPosition(this->GetOwner()->GetPosition() + delta);

	return;
}
