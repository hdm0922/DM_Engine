#pragma once
#include "DM_Scene.h"

#include "SDV_Framework.h"





namespace DM
{
    class EditorScene;
	class Window;
}





namespace SDV
{
	class TileObject;
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

	void selectTileObject(Math::Vector2<UINT> index) { this->selectedTileObject = tileObjectContainer[index.y][index.x]; }
	void createTile(SDV::TileObject* tileSource);

	void registerTileObjects();
	void registerTileObject(SDV::TileObject* tileObject);

	void saveTileMap();

	static Math::Vector2<UINT> getIndex(Math::Vector2<FLOAT> position);
	static Math::Vector2<UINT> getLocation(Math::Vector2<UINT> index);


private:

	SDV::TileObject* tileObjectContainer[104][41];
	const Math::Vector2<UINT> containerSize;

	Window* tileWindow;
	SDV::TileObject* selectedTileObject;
	

};