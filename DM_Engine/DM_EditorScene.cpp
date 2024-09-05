#include "DM_EditorScene.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"





DM::EditorScene::EditorScene(const std::wstring& name)
	: Scene(name)
{
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

	//Application::GetMainWindow()->CreateSubWindow(L"TileWindow", WndProc_Engine, true);
	//Window* tileWindow = Application::GetMainWindow()->GetSubWindow(L"TileWindow");

}





void DM::EditorScene::ExitScene()
{
}
