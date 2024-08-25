#pragma once
#include "framework.h"

#include "DM_Scene.h"





namespace DM
{
	class SceneManager;
}





class DM::SceneManager
{

public:

	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	template <typename T>
	static void CreateScene(const std::wstring& name);

	static void LoadScene(const std::wstring& name);


public:

	static Scene* GetScene(const std::wstring& name);
	static Scene* GetActiveScene() { return SceneManager::activeScene; }


private:

	static Scene* activeScene;
	static std::map<const std::wstring, Scene*> scenes;


};





template<typename T>
inline void DM::SceneManager::CreateScene(const std::wstring& name)
{

	Scene* createScene = static_cast<Scene*>(new T(name));
	if (!createScene) return;

	SceneManager::scenes.insert({ name, createScene });
	createScene->Initialize();

	return;
}
