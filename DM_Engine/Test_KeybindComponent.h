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

    KeybindComponent(const DM::GameObject* owner, const std::wstring& name = L"");
    virtual ~KeybindComponent() override;

    virtual void Initialize();
    virtual void Update();

    void ChangeKeybind_FirstSlot(INT idx, std::vector<INT>* keyset);
    void ChangeKeybind_SecondSlot(INT idx, std::vector<INT>* keyset);


private:

    void initialize_functions();
    void initialize_keybindInfo();

    void listen_keyEvent(INT idx);

private:

    std::vector<std::function<void()>> functions;
    std::vector<std::pair<std::vector<INT>*, std::vector<INT>*>> keybindInfo;


};

