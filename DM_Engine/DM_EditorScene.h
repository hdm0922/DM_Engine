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

	void selectTileIndex(Math::Vector2<UINT> index) { this->selectedTileIndex = index; }
	void createTile(const Math::Vector2<UINT>& tileIndex, Math::Vector2<FLOAT> position);

	void saveTileMap();
	void loadTileMap(); // Test

	static Math::Vector2<UINT> getIndex(Math::Vector2<FLOAT> position);
	static Math::Vector2<UINT> getLocation(Math::Vector2<UINT> index);


private:

	Window* tileWindow;

	Math::Vector2<UINT> selectedTileIndex;
	std::vector<SDV::TileObject*> tiles;


};