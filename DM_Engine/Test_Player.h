#pragma once
#include "Test_TestObject.h"

namespace Test
{
    class Player;
}

class Test::Player :
    public TestObject
{

public:

    Player(const std::wstring& name = L"");
    virtual ~Player() override;

    virtual void Initialize() override;
    virtual void Update() override;




};

