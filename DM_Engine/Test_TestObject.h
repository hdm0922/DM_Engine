#pragma once
#include "DM_GameObject.h"





namespace Test
{
    class TestObject;

}





class Test::TestObject :
    public DM::GameObject
{

public:

    TestObject(const std::wstring& name = L"");
    virtual ~TestObject() override;

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) const override;
    virtual void Destroy() override;

    virtual DM::Animation* GetAnimation(const std::wstring& name) const override;
    static void RegisterAnimation(const std::wstring& name);


private:

    static std::map<const std::wstring, DM::Animation*> animationPool;

};

