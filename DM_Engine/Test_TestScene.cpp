#include "Test_TestScene.h"

#include "Test_TestObject.h"
#include "Test_Player.h"

#include "DM_ResourceManager.h"
#include "DM_TransformComponent.h"
#include "DM_Collider_Box2D.h"
#include "DM_AnimationRenderer.h"
#include "DM_AudioListener.h"
#include "DM_AudioSource.h"





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


	// Test Player
	Player* player = new Player(L"Player");
	this->AddGameObject(player, DM::Enums::LayerType::Entity);

	player->AddComponent<DM::AudioListener>();
	player->AddComponent<DM::Collider_Box2D>();

	player->SetPosition(0,0);
	player->SetOriginalSize(65,130);

	DM::TransformComponent* transform_player =
		player->GetComponent<DM::TransformComponent>();

	transform_player->SetScale(0.5f);
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
	monster->GetComponent<DM::AudioSource>()->Play(DM_TEST_AUDIO_NAME, true);
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
