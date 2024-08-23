#pragma once
#include "DM_Entity.h"





namespace DM
{
    class Component;
}





class DM::Component :
    public Entity
{

public:

    Component(const std::wstring& name = L"", const Enums::ComponentType componentType = Enums::ComponentType::None);
    virtual ~Component() override;

    virtual void Initialize();
    virtual void Update();
    virtual void Render(HDC hdc);


public:

    Enums::ComponentType GetComponentType() const { return this->componentType; }

private:

    const Enums::ComponentType componentType;
};

