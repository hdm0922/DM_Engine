#pragma once
#include "framework.h"

namespace DM
{
	class Window;
}



class DM::Window
{

public:

	Window(const WCHAR* name);
	~Window();

	void Show(INT nCmdShow) const;


public:

	static void SetInstance(HINSTANCE instance) { Window::instance = instance; }
	void SetHandle(HWND handle) { this->handle = handle; }

	static HINSTANCE GetInstance() { return Window::instance; }
	HWND GetHandle() const { return this->handle; }
	const WCHAR* GetName() const { return this->name; }


private:

	ATOM registerWindow(WNDPROC proc) const;


private:

	static HINSTANCE instance;

	HWND handle;
	const WCHAR* name;

};
