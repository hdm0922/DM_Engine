#pragma once
#include "DM_ScriptComponent.h"

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

    void Walk_Right();
    void Walk_Left();
    void Walk_Down();
    void Walk_Up();

    void Run_Right();
    void Run_Left();
    void Run_Down();
    void Run_Up();


public:

    void SetState(State state) { this->state = state; }

    State GetState() const { return this->state; }


private:

    void onState_Idle();
    void onState_Walk();
    void onState_Run();
    void onState_Fight();




private:

    State state;


};