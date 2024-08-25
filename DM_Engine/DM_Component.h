#pragma once
#include "DM_Entity.h"





namespace DM
{
    class Component;
    class GameObject;
}





class DM::Component :
    public Entity
{

public:

    Component(const GameObject* owner,
        const std::wstring& name = L"",
        const Enums::ComponentType componentType =
              Enums::ComponentType::None);

    virtual ~Component() override;

    virtual void Initialize();
    virtual void Update();


public:

    Enums::ComponentType GetComponentType() const { return this->componentType; }
    const GameObject* GetOwner() const { return this->owner; }


private:

    const Enums::ComponentType componentType;
    const GameObject* owner;


};
