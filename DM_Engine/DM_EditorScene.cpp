#include "DM_EditorScene.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"
#include "DM_Input.h"

#include "SDV_Framework.h"

#include "DM_ResourceManager.h"
#include "DM_GameObject.h"
#include "DM_SpriteRenderer.h"




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

	// TEST

	GameObject* testObject = new GameObject(L"TESTOBJECT");
	this->AddGameObject(testObject, DM::Enums::LayerType::Entity);

	testObject->SetPosition(400, 250);
	testObject->SetOriginalSize(200, 200);

	testObject->AddComponent<SpriteRenderer>();
	testObject->GetComponent<SpriteRenderer>()->SetTexture(
		ResourceManager::GetResource<Texture>(SDV_NAME_TEXTURE_MONSTER)
	);
	testObject->GetComponent<SpriteRenderer>()->SetSprite(
		new Sprite({ 150,150 }, { 300,350 }, { 0,0 })
	);
	//

	Scene::Initialize();

	return;
}





void DM::EditorScene::Update()
{
}





void DM::EditorScene::Render(HDC hdc) const
{

	for (UINT iter = 0; iter < 100; iter++)
	{

		INT position_x = SDV_TILE_SIZE.x * iter;
		MoveToEx(hdc, position_x, 0, nullptr);
		LineTo(hdc, position_x, 1000);

		INT position_y = SDV_TILE_SIZE.y * iter;
		MoveToEx(hdc, 0, position_y, nullptr);
		LineTo(hdc, 1000, position_y);

	}

	Scene::Render(hdc);
}





void DM::EditorScene::EnterScene()
{

	this->tileWindow->Show();

}





void DM::EditorScene::ExitScene()
{
}
