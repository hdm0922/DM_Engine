#include "DM_GameLoadManager.h"

#include "DM_ResourceManager.h"
#include "DM_SceneManager.h"
#include "DM_EditorScene.h"

#include "Test_TestScene.h"
#include "Test_Framework.h"
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
    SceneManager::CreateScene<DM::EditorScene>(L"Editor Scene");
}





void DM::GameLoadManager::loadResources_Texture()
{

    ResourceManager::LoadResource<Texture>(
        TEST_NAME_TEXTURE_PLAYER,
        TEST_PATH_TEXTURE_PLAYER
    );

    ResourceManager::LoadResource<Texture>(
        TEST_NAME_TEXTURE_MONSTER,
        TEST_PATH_TEXTURE_MONSTER
    );

    ResourceManager::LoadResource<Texture>(
        SDV_NAME_TEXTURE_SPRING_OUTDOOR,
        SDV_PATH_TEXTURE_SPRING_OUTDOOR
    );
}





void DM::GameLoadManager::loadResources_Animation()
{

    GameLoadManager::loadResources_Animation_PLayer();
    GameLoadManager::loadResources_Animation_Monster();

    return;
}





void DM::GameLoadManager::loadResources_Audio()
{
    ResourceManager::LoadResource<Audio>(
        DM_TEST_AUDIO_NAME,
        DM_TEST_AUDIO_PATH
    );
}





void DM::GameLoadManager::loadResources_Animation_PLayer()
{

    const Math::Vector2<UINT> SIZE = { 250, 250 }; // 65 130
    const Math::Vector2<UINT> OFFSET = { 94, 60 };
    const FLOAT TOTAL_DURATION = 1.0f;


    // Player Idle
    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_IDLE_DOWN,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 8, SIZE.y * 1 }, SIZE, OFFSET), 1, TOTAL_DURATION
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_IDLE_UP,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 0, SIZE.y * 1 }, SIZE, OFFSET), 1, TOTAL_DURATION
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_IDLE_RIGHT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 0, SIZE.y * 0 }, SIZE, OFFSET), 1, TOTAL_DURATION
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_IDLE_LEFT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 6, SIZE.y * 0 }, SIZE, OFFSET), 1, TOTAL_DURATION
    );



    // Player Move
    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_MOVE_RIGHT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 0, SIZE.y * 0 }, SIZE, OFFSET), 6, TOTAL_DURATION / 6
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_MOVE_LEFT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 6, SIZE.y * 0 }, SIZE, OFFSET), 6, TOTAL_DURATION / 6
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_MOVE_UP,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 0, SIZE.y * 1 }, SIZE, OFFSET), 8, TOTAL_DURATION / 8
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_MOVE_DOWN,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 8, SIZE.y * 1 }, SIZE, OFFSET), 4, TOTAL_DURATION / 7
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_PLAYER_MOVE_DOWN,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_PLAYER),
        new Sprite({ SIZE.x * 0, SIZE.y * 2 }, SIZE, OFFSET), 3, TOTAL_DURATION / 7
    );

    return;
}





void DM::GameLoadManager::loadResources_Animation_Monster()
{
    const Math::Vector2<UINT> TOPLEFT = { 514, 92 };
    const Math::Vector2<UINT> SIZE = { 16, 32 };
    const Math::Vector2<UINT> OFFSET = { 0, 0 };
    const FLOAT TOTAL_DURATION = 1.0f;

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_MONSTER_MOVE_DOWN,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_MONSTER),
        new Sprite(TOPLEFT + Math::Vector2<UINT>( SIZE.x * 0, SIZE.y * 0 ), SIZE, OFFSET), 4, TOTAL_DURATION / 4
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_MONSTER_MOVE_RIGHT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_MONSTER),
        new Sprite(TOPLEFT + Math::Vector2<UINT>(SIZE.x * 0, SIZE.y * 1), SIZE, OFFSET), 4, TOTAL_DURATION / 4
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_MONSTER_MOVE_UP,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_MONSTER),
        new Sprite(TOPLEFT + Math::Vector2<UINT>(SIZE.x * 0, SIZE.y * 2), SIZE, OFFSET), 4, TOTAL_DURATION / 4
    );

    ResourceManager::LoadAnimation(TEST_NAME_ANIMATION_MONSTER_MOVE_LEFT,
        ResourceManager::GetResource<Texture>(TEST_NAME_TEXTURE_MONSTER),
        new Sprite(TOPLEFT + Math::Vector2<UINT>(SIZE.x * 0, SIZE.y * 3), SIZE, OFFSET), 4, TOTAL_DURATION / 4
    );

    return;
}
