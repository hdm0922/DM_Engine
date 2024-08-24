#pragma once
#include "DM_Entity.h"
#include "DM_GameObject.h"





namespace DM
{
    class UI_Frame;
}





class DM::UI_Frame:
    public GameObject
{

public:

    UI_Frame(const std::wstring& name = L"");
    virtual ~UI_Frame() override;

    virtual void Initialize();
    virtual void Update();
    virtual void Render(HDC hdc) const;
    virtual void Destroy();

    void Hide();
	void Show();

public:

    virtual void SetParent_UI(UI_Frame* node) { this->parent_UI = node; }
    void SetHidden(BOOL hidden) { this->hidden = true; }
    void SetPosition(FLOAT x, FLOAT y) const { this->SetPosition(Math::Vector2<FLOAT>(x,y)); }
    void SetPosition(const Math::Vector2<FLOAT> position) const;

    UI_Frame* GetParent() const { return this->parent_UI; }
    BOOL GetHidden() const { return this->hidden; }
    Math::Vector2<FLOAT> GetPosition() const;


protected:

    virtual void load();


private:

    UI_Frame* parent_UI;
    std::vector<UI_Frame*> sub_UIs;

    BOOL hidden;

};