#include "DM_ScriptComponent.h"





DM::ScriptComponent::ScriptComponent(const GameObject* owner, const std::wstring& name, const UINT STATE_SIZE)
	: Component(owner, name, Enums::ComponentType::Script)
	, stateChangeConditionMatrix(nullptr)
	, currentStateIdx(0)
	, stateSize(STATE_SIZE)
{

	this->stateChangeConditionMatrix = new std::function<BOOL()>*[STATE_SIZE];
	this->stateEnterEvent = new std::function<void()>[STATE_SIZE];


	for (UINT iter = 0; iter < STATE_SIZE; iter++)
	{
		this->stateChangeConditionMatrix[iter] =
			new std::function<BOOL()>[STATE_SIZE];

		for (UINT jter = 0; jter < STATE_SIZE; jter++)
			this->stateChangeConditionMatrix[iter][jter] = nullptr;
	}	


	for (UINT iter = 0; iter < STATE_SIZE; iter++)
		this->stateEnterEvent[iter] = nullptr;

}





DM::ScriptComponent::~ScriptComponent()
{
}





void DM::ScriptComponent::Initialize()
{
	Component::Initialize();
}





void DM::ScriptComponent::Update()
{

	this->checkStateChangeConditions();

	Component::Update();
}





void DM::ScriptComponent::checkStateChangeConditions()
{

	std::function<BOOL()>* stateChangeConditions =
		this->stateChangeConditionMatrix[this->currentStateIdx];

	for (UINT idx = 0; idx < this->stateSize; idx++)
	{
		if (!stateChangeConditions[idx]) continue;
		if (!stateChangeConditions[idx]()) continue;

		this->SetCurrentState(idx);

		if (this->stateEnterEvent[idx])
			this->stateEnterEvent[idx]();

		return;
	}

	return;
}
