#include "DM_GameLoadManager.h"

#include "DM_ResourceManager.h"
#include "DM_SceneManager.h"

#include "Test_TestScene.h"
#include "Test_TestObject.h"





void DM::GameLoadManager::LoadGame()
{

    GameLoadManager::loadExternalStates();
	GameLoadManager::loadResources();

	GameLoadManager::loadScenes();

	return;
}





void DM::GameLoadManager::loadExternalStates()
{
    FMod::Load();
}





void DM::GameLoadManager::loadResources()
{
    GameLoadManager::loadResources_Texture();
    GameLoadManager::loadResources_Animation();
    GameLoadManager::loadResources_Audio();
}





void DM::GameLoadManager::loadScenes()
{
    SceneManager::CreateScene<Test::TestScene>(DM_TEST_SCENE_NAME);

    SceneManager::LoadScene(DM_TEST_SCENE_NAME);
}





void DM::GameLoadManager::loadResources_Texture()
{

    ResourceManager::LoadResource<Texture>(
        DM_TEST_TEXTURE_BMP_NAME,
        DM_TEST_TEXTURE_BMP_PATH
    );

    ResourceManager::LoadResource<Texture>(
        DM_TEST_TEXTURE_PNG_NAME,
        DM_TEST_TEXTURE_PNG_PATH
    );

}





void DM::GameLoadManager::loadResources_Animation()
{

    ResourceManager::LoadAnimation(DM_TEST_ANIMATION_NAME,
        ResourceManager::GetResource<Texture>(DM_TEST_TEXTURE_BMP_NAME),
        new Sprite({ 0,0 }, { 32,32 }, { 0,0 }), 4, 0.3f
    );

}





void DM::GameLoadManager::loadResources_Audio()
{
    ResourceManager::LoadResource<Audio>(
        DM_TEST_AUDIO_NAME,
        DM_TEST_AUDIO_PATH
    );
}