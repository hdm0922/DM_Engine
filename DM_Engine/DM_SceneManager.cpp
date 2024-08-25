#include "DM_SceneManager.h"





namespace DM
{
	Scene* SceneManager::activeScene = nullptr;
	std::map<const std::wstring, Scene*> SceneManager::scenes = {};
}





void DM::SceneManager::Initialize()
{

	for (auto& iter : SceneManager::scenes)
	{
		iter.second->Initialize();
	}

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





DM::Scene* DM::SceneManager::GetScene(const std::wstring& name)
{
	auto iter = SceneManager::scenes.find(name);
	return (iter == SceneManager::scenes.end()) ?
		nullptr : iter->second;
}





void DM::SceneManager::LoadScene(const std::wstring& name)
{

	if (SceneManager::activeScene) { SceneManager::activeScene->ExitScene(); }

	Scene* loadScene = SceneManager::GetScene(name);
	if (!loadScene) return;

	SceneManager::activeScene = loadScene;
	SceneManager::activeScene->EnterScene();

}
