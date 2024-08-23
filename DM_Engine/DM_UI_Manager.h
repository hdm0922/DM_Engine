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

	static void RequestLoad(UI_Frame* UI) { UI_Manager::UI_loadQueue.push(UI); }
	static void RequestKill(UI_Frame* UI) { UI_Manager::UI_killQueue.push(UI); }

	template <typename T>
	static void Create_UI();


private:

	static void load();
	static void kill();


private:

	static std::queue<UI_Frame*> UI_renderQueue;
	static std::queue<UI_Frame*> UI_loadQueue;
	static std::queue<UI_Frame*> UI_killQueue;
};





template<typename T>
inline void DM::UI_Manager::Create_UI()
{

	UI_Frame* UI = dynamic_cast<UI_Frame*>(new T());
	assert(UI);

	UI_Manager::RequestLoad(UI);

	return;
}