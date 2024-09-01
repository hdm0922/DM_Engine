#pragma once
#include "DM_ScriptComponent.h"

#include "Test_Framework.h"





namespace Test
{
    class PlayerScript;
}





class Test::PlayerScript :
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


private:

    Enums::Direction direction;

};