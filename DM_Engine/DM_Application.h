#pragma once
#include "framework.h"

namespace DM
{
	class Application;

	class Window;
}



class DM::Application
{

public:

	static void Initialize(Window* mainWindow);
	static void Update();
	static void Render();

	static void Run();

public:

	static DM::Window* GetMainWindow() { return Application::mainWindow; }

private:

	static DM::Window* mainWindow;

};

