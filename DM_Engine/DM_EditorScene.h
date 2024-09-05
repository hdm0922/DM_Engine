#pragma once
#include "DM_Scene.h"





namespace DM
{
    class EditorScene;
	class Window;
}





class DM::EditorScene :
	public Scene
{

public:

	EditorScene(const std::wstring& name = L"");
	virtual ~EditorScene() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) const override;

	virtual void EnterScene() override;
	virtual void ExitScene() override;


private:

	Window* tileWindow;


};