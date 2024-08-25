#pragma once
#include "framework.h"

namespace DM
{
	class Application;
	class Window;
	class GameObject;
}



class DM::Application
{

public:

	static void Initialize(Window* mainWindow);
	static void Update();
	static void Render();

	static void Run();

public:

	static Window* GetMainWindow() { return Application::mainWindow; }
	static HDC GetDeviceContext() { return Application::device_context; }

	static GameObject* testObject;
private:

	static void initializeWindow();
	static void clearRenderTarget(HDC hdc);
	static void copyRenderTarget(HDC sourceDC, HDC destDC);

	static HDC getDeviceContext_Back() { return Application::device_context_back; }


private:

	static DM::Window* mainWindow;

	static HDC device_context;
	static HDC device_context_back;
	static HBITMAP buffer_back;

};

