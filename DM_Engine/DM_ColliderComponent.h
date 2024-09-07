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


public:

    void SetColliderPosition_Relative(FLOAT x, FLOAT y) { this->SetColliderPosition_Relative({ x,y }); }
    void SetColliderSize(FLOAT x, FLOAT y) { this->SetColliderSize({ x,y }); }

    void SetColliderPosition_Relative(const Math::Vector2<FLOAT>& position) { this->colliderPosition_relative = position; }
    void SetColliderSize(const Math::Vector2<FLOAT>& size) { this->colliderSize = size; }

    Math::Vector2<FLOAT> GetColliderPosition() const;
    Math::Vector2<FLOAT> GetColliderPosition_Relative() const { return this->colliderPosition_relative; }
    Math::Vector2<FLOAT> GetColliderSize() const;


private:

    const Enums::ColliderType colliderType;

    Math::Vector2<FLOAT> colliderPosition_relative;
    Math::Vector2<FLOAT> colliderSize;


};

