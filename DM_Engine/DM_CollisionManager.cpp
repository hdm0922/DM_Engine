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
		for (UINT jter = iter; jter < static_cast<UINT>(Enums::LayerType::None); jter++)
		{

			if (!SceneManager::GetActiveScene()->GetLayerCollision(iter, jter)) continue;

			CollisionManager::simulateCollision(
				static_cast<Enums::LayerType>(iter),
				static_cast<Enums::LayerType>(jter)
			);

		}

	return;
}





void DM::CollisionManager::simulateCollision(Enums::LayerType layer1, Enums::LayerType layer2)
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
			if (object1 == object2) continue;

			CollisionManager::simulateCollision(collider1, collider2);
		}

	}

	return;
}





void DM::CollisionManager::simulateCollision(ColliderComponent* collider1, ColliderComponent* collider2)
{

	bool b =Math::CollisionChecker::Box2D_Box2D(
		collider1->GetOwner()->GetTopLeft(), collider1->GetOwner()->GetBottomRight(),
		collider2->GetOwner()->GetTopLeft(), collider2->GetOwner()->GetBottomRight()
	);

	if (b) {
		int a = 0;
	}

	return;
}
