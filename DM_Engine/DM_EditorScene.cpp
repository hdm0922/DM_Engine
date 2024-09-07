#include "DM_EditorScene.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"
#include "DM_Layer.h"
#include "DM_Input.h"
#include "DM_Sprite.h"

#include "SDV_Framework.h"
#include "SDV_TileObject.h"

#include "DM_ResourceManager.h"
#include "DM_GameObject.h"
#include "DM_SpriteRenderer.h"
#include "DM_TransformComponent.h"





DM::EditorScene::EditorScene(const std::wstring& name)
	: Scene(name)
	, tileWindow(nullptr)
	, selectedTileIndex({ 45,0 })
	, tiles({})
{

	// TileWindow

	Application::GetMainWindow()->CreateSubWindow(L"TileWindow", WndProc_TileWindow, true);
	this->tileWindow = Application::GetMainWindow()->GetSubWindow(L"TileWindow");

	this->tileWindow->SetTopLeft_Relative({ Application::GetMainWindow()->GetSize().x, 0 });
	this->tileWindow->ResizeWindow({
		static_cast<INT>(43 * SDV_TILE_SIZE.x),
		static_cast<INT>(50 * SDV_TILE_SIZE.y)
	});

	//
}





DM::EditorScene::~EditorScene()
{
}





void DM::EditorScene::Initialize()
{

	// TEST

	//GameObject* testObject = new GameObject(L"TESTOBJECT");
	//this->AddGameObject(testObject, DM::Enums::LayerType::Entity);

	//testObject->SetPosition(400, 250);
	//testObject->SetOriginalSize(200, 200);

	//testObject->AddComponent<SpriteRenderer>();
	//testObject->GetComponent<SpriteRenderer>()->SetTexture(
	//	ResourceManager::GetResource<Texture>(SDV_NAME_TEXTURE_MONSTER)
	//);
	//testObject->GetComponent<SpriteRenderer>()->SetSprite(
	//	new Sprite({ 150,150 }, { 300,350 }, { 0,0 })
	//);
	//

	Scene::Initialize();

	return;
}





void DM::EditorScene::Update()
{

	if (Input::GetKeyPressed(VK_LBUTTON, this->tileWindow))
		this->selectTileIndex(this->getIndex(Input::GetCursorPosition()));

	if (Input::GetKeyPressed(VK_LBUTTON))
		this->createTile(this->selectedTileIndex, Input::GetCursorPosition());

	if (Input::GetKeysPressed({ VK_CONTROL, 'S' }))
		this->saveTileMap();

	if (Input::GetKeysPressed({ VK_CONTROL, 'L' }))
		this->loadTileMap();

	return;
}





void DM::EditorScene::Render(HDC hdc) const
{

	for (UINT iter = 0; iter < 100; iter++)
	{

		INT position_x = SDV_TILE_SIZE.x * iter;
		MoveToEx(hdc, position_x, 0, nullptr);
		LineTo(hdc, position_x, 2000);

		INT position_y = SDV_TILE_SIZE.y * iter;
		MoveToEx(hdc, 0, position_y, nullptr);
		LineTo(hdc, 2000, position_y);

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





void DM::EditorScene::createTile(const Math::Vector2<UINT>& tileIndex, Math::Vector2<FLOAT> position)
{

	SDV::TileObject* tile = new SDV::TileObject(
		new Sprite(EditorScene::getLocation(tileIndex), SDV_TILE_SIZE)
	);

	this->AddGameObject(tile, Enums::LayerType::Tile);
	this->tiles.push_back(tile);

	tile->SetTopLeft(
		this->getLocation(this->getIndex(position))
	);

	return;
}





void DM::EditorScene::saveTileMap()
{

	std::ofstream targetFile(SDV_PATH_TILEMAP_FARM);
	targetFile.clear();

	for (SDV::TileObject* tile : this->tiles)
	{
		Math::Vector2<UINT> tileIndex = this->getIndex(tile->GetSprite()->topLeft);
		Math::Vector2<FLOAT> tilePosition = tile->GetPosition();

		targetFile
			<< tileIndex.x << ' '
			<< tileIndex.y << ' '
			<< tilePosition.x << ' '
			<< tilePosition.y << '\n';
	}

	targetFile.close();

	return;
}





void DM::EditorScene::loadTileMap()
{

	std::ifstream sourceFile(SDV_PATH_TILEMAP_FARM);

	this->GetLayer(Enums::LayerType::Tile)->ClearGameObjects();
	this->tiles.clear();

	std::string str;
	while (std::getline(sourceFile, str))
	{
		std::vector<std::string> tileData = DM::Utility::Split_String_With_WhiteSpace(str);

		DM::Math::Vector2<UINT> tileIndex = { static_cast<UINT>(std::stoi(tileData[0])), static_cast<UINT>(std::stoi(tileData[1])) };
		DM::Math::Vector2<FLOAT> tilePosition	= { std::stof(tileData[2]), std::stof(tileData[3]) };

		this->createTile(tileIndex, tilePosition);
	}

	return;
}





DM::Math::Vector2<UINT> DM::EditorScene::getIndex(Math::Vector2<FLOAT> position)
{
	return Math::Vector2<UINT>(
		static_cast<UINT>(position.x / SDV_TILE_SIZE.x),
		static_cast<UINT>(position.y / SDV_TILE_SIZE.y)
	);
}





DM::Math::Vector2<UINT> DM::EditorScene::getLocation(Math::Vector2<UINT> index)
{
	return Math::Vector2<UINT>(
		(index.x * SDV_TILE_SIZE.x),
		(index.y * SDV_TILE_SIZE.y)
	);
}
