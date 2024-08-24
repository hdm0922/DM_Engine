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