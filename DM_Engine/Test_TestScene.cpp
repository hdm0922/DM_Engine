#include "Test_TestScene.h"

#include "Test_TestObject.h"

#include "DM_ResourceManager.h"
#include "DM_TransformComponent.h"
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
	TestObject* player = new TestObject(L"Player");
	this->AddGameObject(player, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer =
		player->GetComponentHolder()->GetComponent<DM::AnimationRenderer>();
	animationRenderer->PlayAnimation(DM_TEST_ANIMATION_NAME, true);

	player->GetComponentHolder()->AddComponent<DM::AudioListener>();
	///



	/// Test Monster
	TestObject* monster = new TestObject(L"Monster");
	this->AddGameObject(monster, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer_monster =
		monster->GetComponentHolder()->GetComponent<DM::AnimationRenderer>();
	animationRenderer_monster->PlayAnimation(DM_TEST_ANIMATION_NAME, true);

	DM::TransformComponent* transform_monster =
		monster->GetComponentHolder()->GetComponent<DM::TransformComponent>();
	transform_monster->SetPosition({ 50, 50 });

	monster->GetComponentHolder()->AddComponent<DM::AudioSource>();
	monster->GetComponentHolder()->GetComponent<DM::AudioSource>()
		->Play(DM_TEST_AUDIO_NAME, true);

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
