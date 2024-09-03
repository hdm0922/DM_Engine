#pragma once
#include "DM_Entity.h"

#include "DM_Component.h"
#include "DM_Animation.h"
#include "DM_Audio.h"





namespace DM
{
    class GameObject;
}





class DM::GameObject :
    public Entity
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

	void SetOriginalSize(FLOAT x, FLOAT y) { this->SetOriginalSize(Math::Vector2<FLOAT>(x, y)); }
	void SetOriginalSize(const Math::Vector2<FLOAT>& originSize) { this->originSize = originSize; }
	void SetPosition(FLOAT x, FLOAT y) const { this->SetPosition(Math::Vector2<FLOAT>(x, y)); }
	void SetPosition(const Math::Vector2<FLOAT> position) const;

	virtual Math::Vector2<FLOAT> GetSize() const;
	Math::Vector2<FLOAT> GetOriginalSize() const { return this->originSize; }
	Math::Vector2<FLOAT> GetPosition() const;

	Math::Vector2<FLOAT> GetTopLeft() const;
	Math::Vector2<FLOAT> GetBottomRight() const;

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

	Math::Vector2<FLOAT> originSize;


};





template <typename T>
inline void DM::GameObject::AddComponent()
{

	if (this->GetComponent<T>()) return;

	Component* component = static_cast<Component*>(new T(this));
	assert(component); // DEBUG

	this->components.insert(component);

	return;
}





template <typename T>
inline T* DM::GameObject::GetComponent() const
{

	for (Component* component : this->components)
	{
		T* component_to_find = dynamic_cast<T*>(component);
		if (component_to_find) return component_to_find;
	}

	return nullptr;
}