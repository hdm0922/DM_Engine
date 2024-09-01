#include "DM_Application.h"

#include "DM_Window.h"
#include "DM_Input.h"
#include "DM_Time.h"
#include "DM_GameLoadManager.h"
#include "DM_UI_Manager.h"
#include "DM_SceneManager.h"
#include "DM_CollisionManager.h"





namespace DM
{
	Window* Application::mainWindow			= nullptr;

	HDC Application::device_context			= nullptr;
	HDC Application::device_context_back	= nullptr;
	HBITMAP Application::buffer_back		= nullptr;
}





void DM::Application::Initialize(Window* mainWindow)
{

	GameLoadManager::LoadGame();

	Application::mainWindow = mainWindow;
	Application::initializeWindow();

	Input::Initialize();
	Time::Initialize();

	UI_Manager::Initialize();
	SceneManager::Initialize();
	CollisionManager::Initialize();

	return;
}





void DM::Application::Update()
{

	Input::Update();
	Time::Update();

	UI_Manager::Update();
	SceneManager::Update();
	CollisionManager::Update();

	return;
}





void DM::Application::Render()
{

	Application::clearRenderTarget(
		Application::getDeviceContext_Back()
	);

	Application::renderGame(Application::getDeviceContext_Back());

	Application::copyRenderTarget(
		Application::getDeviceContext_Back(),
		Application::GetDeviceContext()
	);

	return;
}





void DM::Application::Run()
{

	Application::Update();
	Application::Render();

	return;
}





void DM::Application::initializeWindow()
{

	Application::device_context = GetDC(
		Application::GetMainWindow()->GetHandle()
	);

	Application::buffer_back = CreateCompatibleBitmap(
		Application::GetDeviceContext(),
		Application::GetMainWindow()->GetSize().x,
		Application::GetMainWindow()->GetSize().y
	);

	Application::device_context_back = CreateCompatibleDC(
		Application::GetDeviceContext()
	);

	HBITMAP oldBitMap = (HBITMAP)SelectObject(
		Application::device_context_back,
		Application::buffer_back
	);

	DeleteObject(oldBitMap);

	return;
}





void DM::Application::clearRenderTarget(HDC hdc)
{

	HBRUSH brush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Rectangle(hdc, -1, -1,
		Application::GetMainWindow()->GetSize().x + 1,
		Application::GetMainWindow()->GetSize().y + 1);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

	return;
}





void DM::Application::renderGame(HDC hdc)
{

	Time::Render(hdc);

	UI_Manager::Render(hdc);
	SceneManager::Render(hdc);
}





void DM::Application::copyRenderTarget(HDC sourceDC, HDC destDC)
{

	BitBlt(
		destDC, 0, 0,
		Application::GetMainWindow()->GetSize().x,
		Application::GetMainWindow()->GetSize().y,
		sourceDC, 0, 0, SRCCOPY
	);

	return;
}