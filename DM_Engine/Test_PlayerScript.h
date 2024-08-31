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

    PlayerScript(const DM::GameObject* owner, const std::wstring& name = L"");
    virtual ~PlayerScript() override;

    virtual void Initialize() override;
    virtual void Update() override;


private:

    void registerKeyEvents();

    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();


private:

    std::map<INT, std::function<void()>> keyEvents;


};

