#include "DM_SceneManager.h"





namespace DM
{
	Scene* SceneManager::activeScene = nullptr;
	std::map<const std::wstring, Scene*> SceneManager::scenes = {};
	Math::Vector2<FLOAT> SceneManager::sceneScale = { 1.0f, 1.0f };
}





void DM::SceneManager::Initialize()
{

	for (auto& iter : SceneManager::scenes)
	{
		iter.second->Initialize();
	}

	SceneManager::LoadScene(L"Editor Scene");

	return;
}





void DM::SceneManager::Update()
{
	if (!SceneManager::activeScene) return;
	SceneManager::activeScene->Update();
}





void DM::SceneManager::Render(HDC hdc)
{
	if (!SceneManager::activeScene) return;
	SceneManager::activeScene->Render(hdc);
}





void DM::SceneManager::LoadScene(const std::wstring& name)
{

	if (SceneManager::activeScene) { SceneManager::activeScene->ExitScene(); }

	Scene* loadScene = SceneManager::GetScene(name);
	if (!loadScene) return;

	SceneManager::activeScene = loadScene;
	SceneManager::activeScene->EnterScene();

}





void DM::SceneManager::ZoomIn()
{
	SceneManager::sceneScale += {0.1f, 0.1f};
}





void DM::SceneManager::ZoomOut()
{
	SceneManager::sceneScale -= {0.1f, 0.1f};
}





DM::Scene* DM::SceneManager::GetScene(const std::wstring& name)
{
	auto iter = SceneManager::scenes.find(name);
	return (iter == SceneManager::scenes.end()) ?
		nullptr : iter->second;
}