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

	// Test Player
	Player* player = new Player(L"Player");
	this->AddGameObject(player, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer =
		player->GetComponent<DM::AnimationRenderer>();
	animationRenderer->Play(DM_TEST_ANIMATION_NAME, true);

	player->AddComponent<DM::AudioListener>();
	player->AddComponent<DM::Collider_Box2D>();
	player->SetPosition(150, 150);
	player->SetSize(32, 32);
	///



	/// Test Monster
	TestObject* monster = new TestObject(L"Monster");
	this->AddGameObject(monster, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer_monster =
		monster->GetComponent<DM::AnimationRenderer>();
	animationRenderer_monster->Play(DM_TEST_ANIMATION_NAME, true);

	DM::TransformComponent* transform_monster =
		monster->GetComponent<DM::TransformComponent>();
	transform_monster->SetPosition({ 50, 50 });

	monster->AddComponent<DM::AudioSource>();
	monster->GetComponent<DM::AudioSource>()->Play(DM_TEST_AUDIO_NAME, true);

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
