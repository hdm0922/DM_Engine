#include "Test_TestObject.h"

#include "DM_ResourceManager.h"
#include "DM_AnimationRenderer.h"





namespace Test
{
	std::map<const std::wstring, DM::Animation*> TestObject::animationPool = {};
}





Test::TestObject::TestObject(const std::wstring& name)
	: DM::GameObject(name)
{
	this->GetComponentHolder()->AddComponent<DM::AnimationRenderer>();
}





Test::TestObject::~TestObject()
{
}





void Test::TestObject::Initialize()
{
	DM::GameObject::Initialize();
}





void Test::TestObject::Update()
{
	DM::GameObject::Update();
}





void Test::TestObject::Render(HDC hdc) const
{
	DM::GameObject::Render(hdc);
}





void Test::TestObject::Destroy()
{
}





DM::Animation* Test::TestObject::GetAnimation(const std::wstring& name) const
{

	auto iter = TestObject::animationPool.find(name);

	return (iter == TestObject::animationPool.end()) ?
		nullptr : iter->second;
}





void Test::TestObject::RegisterAnimation(const std::wstring& name)
{

	DM::Animation* animation = DM::ResourceManager::GetResource<DM::Animation>(name);
	if (!animation) return;

	TestObject::animationPool.insert({ name, animation });
}
