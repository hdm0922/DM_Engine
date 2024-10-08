#pragma once
#include "DM_Component.h"





namespace Test
{
    class KeybindComponent;
}





class Test::KeybindComponent :
    public DM::Component
{

public:

    enum class Action
    {
        Idle,

        Walk_Up,
        Walk_Down,
        Walk_Left,
        Walk_Right,

        Run_Up,
        Run_Down,
        Run_Left,
        Run_Right,

        Switch_To_Run,

        None
    };


public:

    KeybindComponent(const DM::GameObject* owner, const std::wstring& name = L"");
    virtual ~KeybindComponent() override;

    virtual void Initialize();
    virtual void Update();


public:

    BOOL GetKeysPressed(Action action) const;
    BOOL GetKeysReleased(Action action) const;


private:

    std::vector<INT>* keysets;


};

