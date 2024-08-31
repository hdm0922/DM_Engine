#pragma once
#include "DM_ColliderComponent.h"





namespace DM
{
    class Collider_Box2D;
}





class DM::Collider_Box2D :
    public ColliderComponent
{

public:

    Collider_Box2D(const GameObject* owner, const std::wstring& name = L"");
    virtual ~Collider_Box2D() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;


};

