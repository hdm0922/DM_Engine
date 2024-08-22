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

    UI_Frame();
    virtual ~UI_Frame();

    virtual void Initialize();
    virtual void Update();
    virtual void Render(HDC hdc);

    virtual void Load();
    virtual void Kill();

private:

    std::vector<UI_Frame*> subUIs;

};

