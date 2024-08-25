#pragma once
#include "DM_Scene.h"





namespace DM
{
    class TestScene;
}





class DM::TestScene :
    public Scene
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

