#include "DM_Scene.h"

#include "DM_Layer.h"
#include "DM_GameObject.h"





DM::Scene::Scene(const std::wstring& name)
	: Entity(name)
	, layers({})
{
	for (INT iter = 0; iter < static_cast<INT>(Enums::LayerType::None); iter++)
	{
		this->layers.push_back(new Layer());
	}
}





DM::Scene::~Scene()
{
	for (Layer* layer : this->layers)
	{
		delete layer;
		layer = nullptr;
	}
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
