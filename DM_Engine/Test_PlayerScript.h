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


public:

    void SetState(State state) { this->state = state; }

    State GetState() const { return this->state; }


private:

    void registerKeyEvents();

    void onState_Idle();
    void onState_Walk();
    void onState_Run();
    void onState_Fight();

    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();


private:

    std::map<INT, std::function<void()>> keyEvents;

    State state;

};