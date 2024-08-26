#pragma once
#include "DM_Scene.h"





namespace Test
{
    class TestScene;
}





class Test::TestScene :
	public DM::Scene
{

public:

	TestScene(const std::wstring& name = L"");
	virtual ~TestScene() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) const override;

	virtual void EnterScene() override;
	virtual void ExitScene() override;

};

