#pragma once
#include "DM_Entity.h"



namespace DM
{
    class UI_Frame;
}



class DM::UI_Frame:
    public Entity
{

public:

    UI_Frame(const std::wstring& name = L"");
    virtual ~UI_Frame();

    virtual void Initialize();
    virtual void Update();
    virtual void Render(HDC hdc);

    virtual void Load();
    virtual void Kill();

    template <typename T>
    void Create_UI();


public:

    void SetParent_UI(UI_Frame* UI) { this->parent_UI = UI; }

    UI_Frame* GetParent_UI() const { return this->parent_UI; }

private:

    UI_Frame* parent_UI;

    std::vector<UI_Frame*> sub_UIs;

};





template <typename T>
void DM::UI_Frame::Create_UI()
{

    UI_Frame* sub_UI = dynamic_cast<UI_Frame*>(new T());

    sub_UI->Load();
    sub_UI->Initialize();

    sub_UI->SetParent_UI(this);
    this->sub_UIs.push_back(sub_UI);

    return;
}