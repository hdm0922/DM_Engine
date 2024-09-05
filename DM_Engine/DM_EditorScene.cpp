#include "DM_EditorScene.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"
#include "DM_Input.h"





DM::EditorScene::EditorScene(const std::wstring& name)
	: Scene(name)
	, tileWindow(nullptr)
{
	Application::GetMainWindow()->CreateSubWindow(L"TileWindow", WndProc_TileWindow, true);
	this->tileWindow = Application::GetMainWindow()->GetSubWindow(L"TileWindow");

	this->tileWindow->SetTopLeft_Relative({ Application::GetMainWindow()->GetSize().x, 0 });
	this->tileWindow->ResizeWindow(300, 500);

}





DM::EditorScene::~EditorScene()
{
}





void DM::EditorScene::Initialize()
{
}





void DM::EditorScene::Update()
{
}





void DM::EditorScene::Render(HDC hdc) const
{
}





void DM::EditorScene::EnterScene()
{

	this->tileWindow->Show();

}





void DM::EditorScene::ExitScene()
{
}
