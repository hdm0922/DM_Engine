#include "DM_Window.h"

#include "Resource.h"





namespace DM
{
	HINSTANCE Window::instance = nullptr;
}





DM::Window::Window(const std::wstring& name, WNDPROC WndProc, bool renderWindow)
	: Entity(name)
    , renderWindow(renderWindow)
    , topLeft(0, 0)
    , size(1024, 768)
    , subWindows({})
{

    this->registerWindow(WndProc);


	HWND hWnd = CreateWindowW(
		this->GetName().c_str(),
        this->GetName().c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0,
		this->GetSize().x,
        this->GetSize().y,
		nullptr, nullptr,
		Window::GetInstance(),
		nullptr);

    this->SetHandle(hWnd);

}





DM::Window::~Window()
{

}





void DM::Window::Show(INT nCmdShow) const
{

    if (!this->GetRenderWindow()) return;

	ShowWindow(this->GetHandle(), nCmdShow);
	UpdateWindow(this->GetHandle());

    for (auto& iter : this->subWindows)
    {
        Window* subWindow = iter.second;
        subWindow->Show(nCmdShow);
    }

	return;
}





void DM::Window::AddSubWindow(const WCHAR* name, WNDPROC WndProc, bool renderWindow)
{

    Window* subWindow = this->GetSubWindow(name);

    if (subWindow) return;

    subWindow = new Window(name, WndProc, renderWindow);
    this->subWindows.insert({ name, subWindow });

    return;
}





void DM::Window::ResizeWindow(UINT x, UINT y)
{

    this->RearrangeWindow(
        this->GetTopLeft(),
        Math::Vector2<UINT>(x, y)
    );

    return;
}





void DM::Window::ResizeWindow(const Math::Vector2<UINT> size)
{

    this->RearrangeWindow(
        this->GetTopLeft(),
        size
    );

    return;
}





void DM::Window::RearrangeWindow(const Math::Vector2<UINT> topLeft, const Math::Vector2<UINT> size)
{

    this->SetTopLeft(topLeft);
    this->SetSize(size);

    RECT windowRect = { 
        0,0,
        static_cast<LONG>(this->GetSize().x),
        static_cast<LONG>(this->GetSize().y)
    };

    AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

    SetWindowPos(
        this->GetHandle(),
        nullptr,
        this->GetTopLeft().x,
        this->GetTopLeft().y,
        this->GetSize().x,
        this->GetSize().y,
        0
    );

    return;
}





DM::Window* DM::Window::GetSubWindow(const WCHAR* name)
{
    return nullptr;
}





ATOM DM::Window::registerWindow(WNDPROC proc) const
{
    WNDCLASSEXW wcex = {};

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = proc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = Window::GetInstance();
    wcex.hIcon = LoadIcon(Window::GetInstance(), MAKEINTRESOURCE(IDI_DMENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DMENGINE);
    wcex.lpszClassName = this->GetName().c_str();
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}