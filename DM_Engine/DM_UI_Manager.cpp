#include "DM_UI_Manager.h"

#include "DM_UI_Frame.h"
#include "DM_UI_Button.h"


namespace DM
{
	std::queue<UI_Frame*> UI_Manager::UI_renderQueue	= {};
	std::queue<UI_Frame*> UI_Manager::UI_loadQueue		= {};
	std::queue<UI_Frame*> UI_Manager::UI_killQueue		= {};
}





void DM::UI_Manager::Initialize()
{

	UI_Manager::UI_loadQueue.push(new UI_Button());

	return;
}





void DM::UI_Manager::Update()
{

	UI_Manager::load();



	std::queue<UI_Frame*> updateQueue =
		UI_Manager::UI_renderQueue;

	while (!updateQueue.empty())
	{
		updateQueue.front()->Update();
		updateQueue.pop();
	}



	UI_Manager::kill();

	return;
}





void DM::UI_Manager::Render(HDC hdc)
{

	std::queue<UI_Frame*> renderQueue =
		UI_Manager::UI_renderQueue;

	while (!renderQueue.empty())
	{
		renderQueue.front()->Render(hdc);
		renderQueue.pop();
	}

	return;
}





void DM::UI_Manager::load()
{

	if (UI_Manager::UI_loadQueue.empty()) return;

	UI_Frame* UI = UI_Manager::UI_loadQueue.front();
	UI->Load();

	UI_Manager::UI_renderQueue.push(UI);

	return;
}





void DM::UI_Manager::kill()
{

	if (UI_Manager::UI_killQueue.empty()) return;

	UI_Frame* UI_to_kill = UI_Manager::UI_killQueue.front();
	UI_Manager::UI_killQueue.pop();



	std::queue<UI_Frame*> copyQueue = {};

	while (!UI_Manager::UI_renderQueue.empty())
	{
		UI_Frame* UI = UI_Manager::UI_renderQueue.front();
		UI_Manager::UI_renderQueue.pop();

		if (UI == UI_to_kill) { UI->Kill(); }
		else { copyQueue.push(UI); }
	}



	UI_Manager::UI_renderQueue = copyQueue;

	return;
}
