#pragma once
#include "DM_ScriptComponent.h"
#include "SDV_Framework.h"





namespace SDV
{
    class PlayerScript;
}





class SDV::PlayerScript :
    public DM::ScriptComponent
{

public:

    enum class State
    {
        Idle,
        Walk,
        Run,
        Fight,

        None
    };


public:

    PlayerScript(const DM::GameObject* owner, const std::wstring& name = L"");
    virtual ~PlayerScript() override;

    virtual void Initialize() override;
    virtual void Update() override;

    virtual void CollisionEvent_Enter(const DM::GameObject* other) override;
    virtual void CollisionEvent_Collide(const DM::GameObject* other) override;
    virtual void CollisionEvent_Exit(const DM::GameObject* other) override;


private:

    void registerStateChangeConditions();
    void registerStateEnterEvents();

    void translate(FLOAT speed);

    void onState_Idle();
    void onState_Walk();
    void onState_Run();
    void onState_Fight();

    BOOL stateChangeCondition_Idle_to_Walk();
    BOOL stateChangeCondition_Idle_to_Run();

    BOOL stateChangeCondition_Walk_to_Idle();
    BOOL stateChangeCondition_Walk_to_Run();

    BOOL stateChangeCondition_Run_to_Idle();
    BOOL stateChangeCondition_Run_to_Walk();

    void stateEnterEvent_Idle();
    void stateEnterEvent_Walk();
    void stateEnterEvent_Run();


    void blockedByGameObject(const DM::GameObject* object);



private:

    Enums::Direction direction;


};

