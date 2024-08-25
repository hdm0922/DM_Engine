#pragma once
#include "DM_Entity.h"





namespace DM
{
	class Scene;
	class Layer;
	class GameObject;
}





class DM::Scene abstract
	: public Entity
{

public:

	Scene(const std::wstring& name = L"");
	virtual ~Scene() override;

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc) const;

	virtual void EnterScene() = 0;
	virtual void ExitScene() = 0;

	void AddGameObject(GameObject* gameObject, Enums::LayerType layerType);

private:

	std::vector<Layer*> layers;


};

