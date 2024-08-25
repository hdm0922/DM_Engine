#pragma once
#include "framework.h"





namespace DM
{
	class Layer;
	class GameObject;
}





class DM::Layer
{

public:

	Layer();
	~Layer();

	void Initialize();
	void Update();
	void Render(HDC hdc) const;

	void AddGameObject(GameObject* object);

private:

	std::vector<GameObject*> gameObjects;


};

