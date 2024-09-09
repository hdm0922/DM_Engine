#pragma once
#include "SDV_Pawn.h"





namespace SDV
{
    class Player;
}





class SDV::Player :
    public Pawn
{

public:

    Player(const std::wstring& name = L"");
    virtual ~Player() override;

    virtual void Initialize() override;
    virtual void Update() override;


private:

    void bindKeys();

};

