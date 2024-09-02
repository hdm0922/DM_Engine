#pragma once
#include "framework.h"





namespace DM
{
	class CollisionManager;

	class ColliderComponent;
}





class DM::CollisionManager
{

public:

	static void Initialize();
	static void Update();


private:

	static void detectCollision(Enums::LayerType layer);
	static void detectCollision(Enums::LayerType layer1, Enums::LayerType layer2);
	static void detectCollision(ColliderComponent* collider1, ColliderComponent* collider2);

	static void handleCollision(ColliderComponent* collider1, ColliderComponent* collider2, BOOL collision);


private:

	static std::set<std::pair<UINT64, UINT64>> objectsInCollision;

};