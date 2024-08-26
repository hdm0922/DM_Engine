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

	static void loadResources();
	static void loadScenes();
	static void registerAnimations();


};

