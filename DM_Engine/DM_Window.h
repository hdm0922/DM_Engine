#pragma once
#include "framework.h"
#include "Resource.h"

namespace DM
{
	class Window;
}



class DM::Window
{

public:

	Window(const WCHAR* name, WNDPROC WndProc, bool renderWindow);
	~Window();

	void Show(INT nCmdShow) const;
	void AddSubWindow(const WCHAR* name, WNDPROC WndProc, bool renderWindow);


public:

	static void SetInstance(HINSTANCE instance) { Window::instance = instance; }
	void SetHandle(HWND handle) { this->handle = handle; }
	void SetRenderWindow(bool render) { this->renderWindow = render; }
	void SetSize(const Math::Vector2<UINT>& size) { this->size = size; }

	static HINSTANCE GetInstance() { return Window::instance; }
	HWND GetHandle() const { return this->handle; }
	const WCHAR* GetName() const { return this->name; }
	bool GetRenderWindow() const { return this->renderWindow; }
	Math::Vector2<UINT> GetSize() const { return this->size; }
	Window* GetSubWindow(const WCHAR* name);


private:

	ATOM registerWindow(WNDPROC proc) const;


private:

	static HINSTANCE instance;

	HWND handle;
	const WCHAR* name;
	bool renderWindow;
	Math::Vector2<UINT> size;

	std::map<const WCHAR*, Window*> subWindows;
};
