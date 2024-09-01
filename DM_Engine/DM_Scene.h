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


public:

	void SetLayerCollision(UINT layer1, UINT layer2, BOOL collision) { this->layerCollisionMatrix[std::min(layer1, layer2)][std::max(layer1, layer2)] = collision; }

	Layer* GetLayer(Enums::LayerType layerType) const { return this->layers[static_cast<UINT>(layerType)]; }
	BOOL GetLayerCollision(UINT layer1, UINT layer2) const { return this->layerCollisionMatrix[layer1][layer2]; }


private:

	std::vector<Layer*> layers;

	BOOL** layerCollisionMatrix;
	const INT LAYER_SIZE;


};

