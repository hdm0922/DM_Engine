#include "DM_Application.h"



namespace DM
{
	Window* Application::mainWindow = nullptr;
}





void DM::Application::Initialize(Window* mainWindow)
{

	Application::mainWindow = mainWindow;

	return;
}





void DM::Application::Update()
{

	return;
}





void DM::Application::Render()
{

	return;
}





void DM::Application::Run()
{

	Application::Update();
	Application::Render();

	return;
}
