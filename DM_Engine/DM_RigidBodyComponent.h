#pragma once
#include "DM_Component.h"





namespace DM
{
    class RigidBodyComponent;
}





class DM::RigidBodyComponent :
    public Component
{

public:

    RigidBodyComponent(const GameObject* owner, const std::wstring& name = L"");
    virtual ~RigidBodyComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;


public:

    void SetVelocity(FLOAT x, FLOAT y) { this->SetVelocity({ x,y }); }
    void SetVelocity(Math::Vector2<FLOAT> velocity) { this->velocity = velocity; }
    void SetAccel(FLOAT x, FLOAT y) { this->SetAccel({ x,y }); }
    void SetAccel(Math::Vector2<FLOAT> accel) { this->accel = accel; }
    void SetMass(FLOAT mass) { this->mass = mass; }
    void SimulatePhysics(BOOL simulate) { this->simulatePhysics = simulate; }

    Math::Vector2<FLOAT> GetVelocity() const { return this->velocity; }
    Math::Vector2<FLOAT> GetAccel() const { return this->accel; }
    FLOAT GetMass() const { return this->mass; }
    BOOL SimulatingPhysics() const { return this->simulatePhysics; }


private:

    void updatePhysics();

private:

    Math::Vector2<FLOAT> velocity;
    Math::Vector2<FLOAT> accel;

    FLOAT mass;
    BOOL simulatePhysics;


};

