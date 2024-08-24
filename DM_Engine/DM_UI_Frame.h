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

    template <typename T>
    T* CreateSubUI();



public:

    virtual void SetParent_UI(UI_Frame* UI) { this->parent_UI = UI; }
    void SetToggleKeyCode(UINT keyCode) { this->toggleKeyCode = keyCode; }
    void SetHidden(BOOL hidden) { this->hidden = hidden; }
    void SetPosition(FLOAT x, FLOAT y) const { this->SetPosition(Math::Vector2<FLOAT>(x,y)); }
    void SetPosition(const Math::Vector2<FLOAT> position) const;

    UI_Frame* GetParent() const { return this->parent_UI; }
    UINT GetToggleKeyCode() const { return this->toggleKeyCode; }
    BOOL GetHidden() const { return this->hidden; }
    Math::Vector2<FLOAT> GetPosition() const;


protected:

    virtual void load();
    virtual void checkUserInputEvents();


private:

    UI_Frame* parent_UI;
    std::vector<UI_Frame*> sub_UIs;

    BOOL hidden;
    BOOL hidden_right_before_hide;
    UINT toggleKeyCode;

};





template<typename T>
inline T* DM::UI_Frame::CreateSubUI()
{

    UI_Frame* sub_UI = static_cast<UI_Frame*>(new T());
    assert(sub_UI);

    this->sub_UIs.push_back(sub_UI);

    return dynamic_cast<T*>(sub_UI);
}
