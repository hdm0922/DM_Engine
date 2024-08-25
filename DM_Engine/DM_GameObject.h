#pragma once
#include "DM_Entity.h"



namespace DM
{
    class GameObject;
	class ComponentHolder;
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


public:

	void SetPosition(FLOAT x, FLOAT y) const { this->SetPosition(Math::Vector2<FLOAT>(x, y)); }
	void SetPosition(const Math::Vector2<FLOAT> position) const;

	Math::Vector2<FLOAT> GetPosition() const;
	ComponentHolder* GetComponentHolder() const { return this->componentHolder; }


private:

	ComponentHolder* componentHolder;


};