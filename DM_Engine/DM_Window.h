#pragma once
#include "DM_Entity.h"
#include "Resource.h"

namespace DM
{
	class Window;
}



class DM::Window
	: public Entity
{

public:

	Window(const std::wstring& name, WNDPROC WndProc, bool renderWindow);
	~Window();

	void Show(INT nCmdShow = 10) const;
	void CreateSubWindow(const std::wstring& name, WNDPROC WndProc, bool renderWindow);
	void ResizeWindow(INT x, INT y);
	void ResizeWindow(const Math::Vector2<INT> size);
	void RearrangeWindow(const Math::Vector2<INT> topLeft, const Math::Vector2<INT> size);


public:

	static void SetInstance(HINSTANCE instance) { Window::instance = instance; }
	void SetHandle(HWND handle) { this->handle = handle; }
	void SetRenderWindow(bool render) { this->renderWindow = render; }
	void SetTopLeft_Relative(const Math::Vector2<INT>& topLeft) { this->topLeft = topLeft; }
	void SetSize(const Math::Vector2<INT>& size) { this->size = size; }

	static HINSTANCE GetInstance() { return Window::instance; }
	HWND GetHandle() const { return this->handle; }
	BOOL GetRenderWindow() const { return this->renderWindow; }
	Math::Vector2<INT> GetTopLeft_Relative() const { return this->topLeft; }
	Math::Vector2<INT> GetTopLeft() const { return (this->parentWindow ? this->parentWindow->GetTopLeft_Relative() : Math::Vector2<INT>()) + this->topLeft; }
	Math::Vector2<INT> GetSize() const { return this->size; }
	Window* GetSubWindow(const std::wstring& name);


private:

	ATOM registerWindow(WNDPROC proc) const;


private:

	static HINSTANCE instance;

	HWND handle;

	BOOL renderWindow;
	Math::Vector2<INT> topLeft;
	Math::Vector2<INT> size;

	Window* parentWindow;
	std::map<const std::wstring, Window*> subWindows;
};
