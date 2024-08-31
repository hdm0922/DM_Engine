#pragma once
#include "DM_Component.h"





namespace DM
{
    class ColliderComponent;
}





class DM::ColliderComponent abstract:
    public Component
{

public:

    ColliderComponent(const GameObject* owner, const std::wstring& name, const Enums::ColliderType colliderType);
    virtual ~ColliderComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) = 0;


private:

    const Enums::ColliderType colliderType;


};

