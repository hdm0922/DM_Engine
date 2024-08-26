#pragma once
#include "framework.h"
#include "DM_Component.h"





namespace DM
{
	class ComponentHolder;
	class Component;
	class GameObject;
}





class DM::ComponentHolder
{

public:

	ComponentHolder(const GameObject* owner);
	~ComponentHolder();

	void Initialize();
	void Update();

	template <typename Child>
	void AddComponent();


public:

	template <typename Child>
	Child* GetComponent() const;

	const GameObject* GetOwner() const { return this->owner; }


private:

	struct compareFunction
	{
		bool operator()(const Component* left, const Component* right) const
		{
			return left->GetComponentType() < right->GetComponentType();
		}
	};


private:

	const GameObject* owner;
	std::set<Component*, compareFunction> components;

};





template<typename T>
inline void DM::ComponentHolder::AddComponent()
{

	if (this->GetComponent<T>()) return;


	Component* component = static_cast<Component*>(new T(this->GetOwner()));
	assert(component); // DEBUG

	this->components.insert(component);

	return;
}





template<typename T>
inline T* DM::ComponentHolder::GetComponent() const
{

	for (Component* component : this->components)
	{
		T* component_to_find = dynamic_cast<T*>(component);
		if (component_to_find) return component_to_find;
	}

	return nullptr;
}