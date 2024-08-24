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

	ComponentHolder* GetComponentHolder() const { return this->componentHolder; }


private:

	ComponentHolder* componentHolder;


};