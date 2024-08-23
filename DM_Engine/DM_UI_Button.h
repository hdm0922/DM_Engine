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
    virtual void Render(HDC hdc) const override;
    virtual void Destroy() override;

    virtual void OnEvent_Click();


public:
    //template <class _Fx, class... _Types>
    //void SetClickEvent(_Fx&& function, _Types&&... UI) { clickEvent = std::move(std::bind(function, UI)); }
    //void SetClickEvent(const std::function<void()>& function) { this->clickEvent = function; }
    std::function<void()> clickEvent;

protected:

    virtual void load() override;
    

private:

    

    // temp
    Math::Vector2<FLOAT> size;
};

