#include "DM_EditorScene.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"





DM::EditorScene::EditorScene(const std::wstring& name)
	: Scene(name)
{
	Application::GetMainWindow()->CreateSubWindow(L"TileWindow", WndProc_TileWindow, true);
	this->tileWindow = Application::GetMainWindow()->GetSubWindow(L"TileWindow");

	this->tileWindow->SetTopLeft_Relative({ 100, 0 });
	this->tileWindow->ResizeWindow(500, 300);

	auto k1 = Application::GetMainWindow()->GetTopLeft();
	auto k2 = this->tileWindow->GetTopLeft();
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
