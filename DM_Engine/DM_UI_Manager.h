#pragma once
#include "framework.h"



namespace DM
{
	class UI_Manager;
	class UI_Frame;
}



class DM::UI_Manager
{

public:

	static void Initialize();
	static void Update();
	static void Render(HDC hdc);


private:

	static void load();
	static void kill();


private:

	static std::queue<UI_Frame*> UI_renderQueue;
	static std::queue<UI_Frame*> UI_loadQueue;
	static std::queue<UI_Frame*> UI_killQueue;
};

