#include "DM_CollisionManager.h"

#include "DM_Scene.h"
#include "DM_Layer.h"
#include "DM_GameObject.h"
#include "DM_SceneManager.h"
#include "DM_ColliderComponent.h"





namespace DM
{
	std::set<std::pair<UINT64, UINT64>> CollisionManager::objectsInCollision = {};
}





void DM::CollisionManager::Initialize()
{
}





void DM::CollisionManager::Update()
{

	for (UINT iter = 0; iter < static_cast<UINT>(Enums::LayerType::None); iter++)
	{

		CollisionManager::detectCollision(static_cast<Enums::LayerType>(iter));

		for (UINT jter = iter + 1; jter < static_cast<UINT>(Enums::LayerType::None); jter++)
		{

			if (!SceneManager::GetActiveScene()->GetLayerCollision(iter, jter)) continue;

			CollisionManager::detectCollision(
				static_cast<Enums::LayerType>(iter),
				static_cast<Enums::LayerType>(jter)
			);

		}

	}

	return;
}





void DM::CollisionManager::detectCollision(Enums::LayerType layer)
{

	const std::vector<GameObject*>& gameObjects = SceneManager::GetActiveScene()->GetLayer(layer)->GetGameObjects();

	for (UINT iter = 0; iter < gameObjects.size(); iter++)
	{

		ColliderComponent* collider1 = gameObjects[iter]->GetComponent<ColliderComponent>();
		if (!collider1) continue;

		for (UINT jter = iter + 1; jter < gameObjects.size(); jter++)
		{

			ColliderComponent* collider2 = gameObjects[jter]->GetComponent<ColliderComponent>();
			if (!collider2) continue;

			CollisionManager::detectCollision(collider1, collider2);

		}

	}

	return;
}





void DM::CollisionManager::detectCollision(Enums::LayerType layer1, Enums::LayerType layer2)
{

	const std::vector<GameObject*>& gameObjects1 = SceneManager::GetActiveScene()->GetLayer(layer1)->GetGameObjects();
	const std::vector<GameObject*>& gameObjects2 = SceneManager::GetActiveScene()->GetLayer(layer2)->GetGameObjects();

	for (GameObject* object1 : gameObjects1)
	{

		ColliderComponent* collider1 = object1->GetComponent<ColliderComponent>();
		if (!collider1) continue;

		for (GameObject* object2 : gameObjects2)
		{

			ColliderComponent* collider2 = object2->GetComponent<ColliderComponent>();
			if (!collider2) continue;

			CollisionManager::detectCollision(collider1, collider2);
		}

	}

	return;
}





void DM::CollisionManager::detectCollision(ColliderComponent* collider1, ColliderComponent* collider2)
{

	BOOL collision = Math::CollisionChecker::Box2D_Box2D(
		collider1->GetTopLeft(), collider1->GetBottomRight(),
		collider2->GetTopLeft(), collider2->GetBottomRight()
	);

	CollisionManager::handleCollision(collider1, collider2, collision);

	return;
}





void DM::CollisionManager::handleCollision(ColliderComponent* collider1, ColliderComponent* collider2, BOOL collision)
{

	std::pair<UINT64,UINT64> key = { (UINT64)(collider1), (UINT64)(collider2) };
	auto iter = CollisionManager::objectsInCollision.find(key);

	if (iter == CollisionManager::objectsInCollision.end())
	{ // 이전 frame 충돌 X

		if (collision)
		{
			CollisionManager::objectsInCollision.insert(key);
			collider1->CollisionEvent_Enter(collider2->GetOwner());
			collider2->CollisionEvent_Enter(collider1->GetOwner());
		}

	}
	else
	{ // 이전 frame 충돌 O

		if (collision)
		{
			collider1->CollisionEvent_Collide(collider2->GetOwner());
			collider2->CollisionEvent_Collide(collider1->GetOwner());
		}
		else
		{
			CollisionManager::objectsInCollision.erase(iter);
			collider1->CollisionEvent_Exit(collider2->GetOwner());
			collider2->CollisionEvent_Exit(collider1->GetOwner());
		}

	}


	return;
}
