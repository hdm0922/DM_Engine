#pragma once
#include "DM_UI_Frame.h"





namespace DM
{
    class UI_Status;
}





class DM::UI_Status :
    public UI_Frame
{

public:

    UI_Status(const std::wstring& name = L"");
    virtual ~UI_Status() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;
    virtual void Destroy() override;


protected:

    virtual void load();

    void close() { this->Hide(); }

private:

};

