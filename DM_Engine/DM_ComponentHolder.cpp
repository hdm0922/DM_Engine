#include "DM_ComponentHolder.h"

#include "DM_TransformComponent.h"





DM::ComponentHolder::ComponentHolder(const DM::GameObject* owner)
	: owner(owner)
	, components({})
{
	this->AddComponent<TransformComponent>();
}





DM::ComponentHolder::~ComponentHolder()
{
	for (Component* component : this->components)
	{
		delete component;
		component = nullptr;
	}
}





void DM::ComponentHolder::Initialize()
{
	for (Component* component : this->components)
	{
		component->Initialize();
	}
}





void DM::ComponentHolder::Update()
{
	for (Component* component : this->components)
	{
		component->Update();
	}
}
