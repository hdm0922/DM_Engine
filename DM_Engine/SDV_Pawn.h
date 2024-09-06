#pragma once
#include "DM_GameObject.h"





namespace SDV
{
    class Pawn;
}





class SDV::Pawn :
    public DM::GameObject
{

public:

    Pawn(const std::wstring& name = L"");
    virtual ~Pawn() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;
    virtual void Destroy() override;


};

