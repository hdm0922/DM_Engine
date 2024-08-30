#include "Test_TestObject.h"

#include "DM_ResourceManager.h"
#include "DM_AnimationRenderer.h"





Test::TestObject::TestObject(const std::wstring& name)
	: DM::GameObject(name)
{
	this->AddComponent<DM::AnimationRenderer>();
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