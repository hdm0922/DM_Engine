#include "DM_CollisionManager.h"

#include "DM_Scene.h"
#include "DM_Layer.h"
#include "DM_GameObject.h"
#include "DM_SceneManager.h"
#include "DM_ColliderComponent.h"





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
		collider1->GetOwner()->GetTopLeft(), collider1->GetOwner()->GetBottomRight(),
		collider2->GetOwner()->GetTopLeft(), collider2->GetOwner()->GetBottomRight()
	);

	if (!collision) return;

	return;
}
