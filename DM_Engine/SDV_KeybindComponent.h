#pragma once
#include "DM_Component.h"





namespace SDV
{
    class KeybindComponent;
}





class SDV::KeybindComponent :
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

    void SetKeys(Action action, const std::vector<INT>& keys) { this->keysets[static_cast<UINT>(action)] = keys; }

    BOOL GetKeysPressed(Action action) const;
    BOOL GetKeysReleased(Action action) const;


private:

    std::vector<INT>* keysets;


};

