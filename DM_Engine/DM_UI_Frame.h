#pragma once
#include "DM_GameObject.h"
#include "DM_ObjectTree.h"




namespace DM
{
    class UI_Frame;
}





class DM::UI_Frame:
    public GameObject,
    public ObjectTree<UI_Frame>
{

public:

    UI_Frame(const std::wstring& name = L"");
    virtual ~UI_Frame() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;
    virtual void Destroy() override;


protected:

    virtual void load();


};