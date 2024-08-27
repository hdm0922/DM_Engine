#pragma once
#include "framework.h"





namespace DM
{
	class GameLoadManager;
}





class DM::GameLoadManager
{

public:

	static void LoadGame();


private:

	static void loadExternalStates();
	static void loadResources();
	static void loadScenes();
	static void registerResources();

	static void loadResources_Texture();
	static void loadResources_Animation();
	static void loadResources_Audio();

	static void registerResources_Animation();


};

