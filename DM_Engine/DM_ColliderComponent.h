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

    void CollisionEvent_Enter(const GameObject* other);
    void CollisionEvent_Collide(const GameObject* other);
    void CollisionEvent_Exit(const GameObject* other);


private:

    const Enums::ColliderType colliderType;


};

