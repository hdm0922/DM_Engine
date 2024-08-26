#include "Test_TestScene.h"

#include "Test_TestObject.h"
#include "DM_AnimationRenderer.h"





Test::TestScene::TestScene(const std::wstring& name)
	: Scene(name)
{
}





Test::TestScene::~TestScene()
{
}





void Test::TestScene::Initialize()
{

	TestObject* player = new TestObject(L"Player");
	this->AddGameObject(player, DM::Enums::LayerType::Entity);

	DM::AnimationRenderer* animationRenderer =
		player->GetComponentHolder()->GetComponent<DM::AnimationRenderer>();

	animationRenderer->PlayAnimation(DM_TEST_ANIMATION_NAME, true);


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
