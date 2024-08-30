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


};

