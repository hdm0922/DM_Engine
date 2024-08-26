#pragma once
#include "DM_Entity.h"

#include "DM_ComponentHolder.h"





namespace DM
{
    class GameObject;
	class Animation;
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

	static void RegisterAnimation(const std::wstring& name);


public:

	void SetPosition(FLOAT x, FLOAT y) const { this->SetPosition(Math::Vector2<FLOAT>(x, y)); }
	void SetPosition(const Math::Vector2<FLOAT> position) const;

	Math::Vector2<FLOAT> GetPosition() const;
	ComponentHolder* GetComponentHolder() const { return this->componentHolder; }


private:

	static std::map<const std::wstring, Animation*> animationPool;

	ComponentHolder* componentHolder;


};