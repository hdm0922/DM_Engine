#include "DM_Scene.h"

#include "DM_Layer.h"
#include "DM_GameObject.h"
#include "DM_Camera.h"





DM::Scene::Scene(const std::wstring& name)
	: Entity(name)
	, layers({})
	, layerCollisionMatrix(nullptr)
	, LAYER_SIZE(static_cast<INT>(Enums::LayerType::None))
	, camera(new Camera(name + L" Camera"))
{

	for (INT iter = 0; iter < LAYER_SIZE; iter++)
	{
		this->layers.push_back(new Layer());
	}



	this->layerCollisionMatrix = new BOOL * [LAYER_SIZE];

	for (INT iter = 0; iter < LAYER_SIZE; iter++)
	{
		this->layerCollisionMatrix[iter] = new BOOL[LAYER_SIZE];

		for (INT jter = 0; jter < LAYER_SIZE; jter++)
			this->layerCollisionMatrix[iter][jter] = false;
	}

}





DM::Scene::~Scene()
{

	for (Layer* layer : this->layers)
	{
		delete layer;
		layer = nullptr;
	}

	for (INT iter = 0; iter < LAYER_SIZE; iter++)
	{
		delete[] this->layerCollisionMatrix[iter];
	}	delete[] this->layerCollisionMatrix;

}





void DM::Scene::Initialize()
{
	for (Layer* layer : this->layers)
	{
		layer->Initialize();
	}
}





void DM::Scene::Update()
{
	for (Layer* layer : this->layers)
	{
		layer->Update();
	}

	this->camera->Update();
}





void DM::Scene::Render(HDC hdc) const
{
	for (Layer* layer : this->layers)
	{
		layer->Render(hdc);
	}
}





void DM::Scene::AddGameObject(GameObject* gameObject, Enums::LayerType layerType)
{
	this->layers[static_cast<UINT>(layerType)]->AddGameObject(gameObject);
}