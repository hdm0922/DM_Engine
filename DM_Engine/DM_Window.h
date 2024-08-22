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

	void Show(INT nCmdShow) const;
	void CreateSubWindow(const std::wstring& name, WNDPROC WndProc, bool renderWindow);
	void ResizeWindow(UINT x, UINT y);
	void ResizeWindow(const Math::Vector2<UINT> size);
	void RearrangeWindow(const Math::Vector2<UINT> topLeft, const Math::Vector2<UINT> size);


public:

	static void SetInstance(HINSTANCE instance) { Window::instance = instance; }
	void SetHandle(HWND handle) { this->handle = handle; }
	void SetRenderWindow(bool render) { this->renderWindow = render; }
	void SetTopLeft(const Math::Vector2<UINT>& topLeft) { this->topLeft = topLeft; }
	void SetSize(const Math::Vector2<UINT>& size) { this->size = size; }

	static HINSTANCE GetInstance() { return Window::instance; }
	HWND GetHandle() const { return this->handle; }
	bool GetRenderWindow() const { return this->renderWindow; }
	Math::Vector2<UINT> GetTopLeft() const { return this->topLeft; }
	Math::Vector2<UINT> GetSize() const { return this->size; }
	Window* GetSubWindow(const std::wstring& name);


private:

	ATOM registerWindow(WNDPROC proc) const;


private:

	static HINSTANCE instance;

	HWND handle;

	bool renderWindow;
	Math::Vector2<UINT> topLeft;
	Math::Vector2<UINT> size;

	std::map<const std::wstring, Window*> subWindows;
};
