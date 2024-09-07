#include "Test_TestScene.h"

#include "Test_TestObject.h"
#include "Test_Player.h"
#include "Test_GameStateComponent.h"

#include "DM_ResourceManager.h"
#include "DM_TransformComponent.h"
#include "DM_Collider_Box2D.h"
#include "DM_AnimationRenderer.h"
#include "DM_AudioListener.h"
#include "DM_AudioSource.h"
#include "DM_Camera.h"





Test::TestScene::TestScene(const std::wstring& name)
	: Scene(name)
{
}





Test::TestScene::~TestScene()
{
}





void Test::TestScene::Initialize()
{

	// Scene Init

	this->SetLayerCollision(
		static_cast<UINT>(DM::Enums::LayerType::Entity),
		static_cast<UINT>(DM::Enums::LayerType::Entity),
		true
	);

	//


	// Test Player 1. 메모리 할당 2. Transform 결정 3. Component들 추가
	Player* player = new Player(L"Player");
	this->AddGameObject(player, DM::Enums::LayerType::Entity);

	DM::TransformComponent* transform_player =
		player->GetComponent<DM::TransformComponent>();

	transform_player->SetScale(0.5f);
	player->SetPosition(0, 0);
	player->SetOriginalSize(65, 130);

	player->AddComponent<DM::AudioListener>();
	player->AddComponent<DM::Collider_Box2D>();


	///


	/// Test Monster
	TestObject* monster = new TestObject(L"Monster");
	this->AddGameObject(monster, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer_monster =
		monster->GetComponent<DM::AnimationRenderer>();

	animationRenderer_monster->Play(TEST_NAME_ANIMATION_MONSTER_MOVE_DOWN, true);



	DM::TransformComponent* transform_monster =
		monster->GetComponent<DM::TransformComponent>();

	transform_monster->SetPosition({ 150, 150 });
	monster->SetOriginalSize(16, 32);



	monster->AddComponent<DM::Collider_Box2D>();
	monster->AddComponent<DM::AudioSource>();
	//monster->GetComponent<DM::AudioSource>()->Play(DM_TEST_AUDIO_NAME, true);

	GameStateComponent* gameState_monster = monster->GetComponent<GameStateComponent>();
	gameState_monster->SetPlayerBlocking(true);
	///

	/// Camera
	
	this->GetCamera()->SetRenderTarget(player);

	///

	DM::Scene::Initialize();
}





void Test::TestScene::Update()
{

	DM::Scene::Update();
}





void Test::TestScene::Render(HDC hdc) const
{

	DM::Scene::Render(hdc);
}





void Test::TestScene::EnterScene()
{
}





void Test::TestScene::ExitScene()
{
}
