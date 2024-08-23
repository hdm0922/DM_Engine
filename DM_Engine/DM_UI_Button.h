#pragma once
#include "DM_UI_Frame.h"



namespace DM
{
    class UI_Button;
}



class DM::UI_Button :
    public UI_Frame
{

public:

    UI_Button(const std::wstring& name = L"");
    virtual ~UI_Button() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

    virtual void Load() override;
    virtual void Kill() override;


    // temp
    Math::Vector2<FLOAT> topLeft;
    Math::Vector2<FLOAT> size;

}

