#pragma once
#include "DM_Component.h"





namespace Test
{
    class GameStateComponent;
}





class Test::GameStateComponent :
    public DM::Component
{

public:

    GameStateComponent(const DM::GameObject* owner, const std::wstring& name = L"");
    virtual ~GameStateComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;


public:

    void SetPlayerBlocking(BOOL block) { this->blocksPlayer = block; }

    BOOL BlocksPlayer() const { return this->blocksPlayer; }


private:

    BOOL blocksPlayer;

};

