#include "DM_Layer.h"

#include "DM_GameObject.h"





DM::Layer::Layer()
	: gameObjects({})
{
	//for (UINT iter = 0; iter < static_cast<UINT>(Enums::LayerType::Background); iter++)
	//{

	//}
}





DM::Layer::~Layer()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		delete gameObject;
		gameObject = nullptr;
	}
}





void DM::Layer::Initialize()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->Initialize();
	}
}





void DM::Layer::Update()
{
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->Update();
	}
}





void DM::Layer::Render(HDC hdc) const
{
	for (GameObject* gameObject : this->gameObjects)
	{
		gameObject->Render(hdc);
	}
}





void DM::Layer::AddGameObject(GameObject* object)
{
	if (!object) return;
	this->gameObjects.push_back(object);
}
