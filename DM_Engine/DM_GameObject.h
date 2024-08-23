#pragma once
#include "DM_Entity.h"
#include "DM_ObjectTree.h"
#include "DM_Component.h"



namespace DM
{
    class GameObject;
}





class DM::GameObject :
    public Entity,
    public ObjectTree<GameObject>
{

public:

	GameObject(const std::wstring& name = L"");
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc) const;
	virtual void Destroy();

	template <typename T>
	void AddComponent();


public:

	template <typename T>
	T* GetComponent() const;


private:

	struct compareFunction
	{
		bool operator()(const Component* left, const Component* right) const
		{
			return left->GetComponentType() < right->GetComponentType();
		}
	};


private:

	std::set<Component*, compareFunction> components;

};





template<typename T>
inline void DM::GameObject::AddComponent()
{

	if (this->GetComponent<T>()) return;

	Component* component = static_cast<Component*>(new T(this));
	assert(component); // DEBUG

	this->components.insert(component);

	return;
}





template<typename T>
inline T* DM::GameObject::GetComponent() const
{

	for (Component* component : this->components)
	{
		T* component_to_find = dynamic_cast<T*>(component);
		if (component_to_find) return component_to_find;
	}

	return nullptr;
}
