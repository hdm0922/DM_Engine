#include "DM_Application.h"

#include "DM_Window.h"

namespace DM
{
	Window* Application::mainWindow			= nullptr;

	HDC Application::device_context			= nullptr;
	HDC Application::device_context_back	= nullptr;
	HBITMAP Application::buffer_back		= nullptr;
}





void DM::Application::Initialize(Window* mainWindow)
{

	Application::mainWindow = mainWindow;

	Application::initializeWindow();




	return;
}





void DM::Application::Update()
{

	return;
}





void DM::Application::Render()
{

	Application::clearRenderTarget(
		Application::getDeviceContext_Back()
	);

	// render all objects

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