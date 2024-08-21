#include "DM_Window.h"

#include "Resource.h"





namespace DM
{
	HINSTANCE Window::instance = nullptr;

    LRESULT CALLBACK WndProc_Engine(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
}





DM::Window::Window(const WCHAR* name)
	: name(name)
{

    this->registerWindow(WndProc_Engine);

	HWND hWnd = CreateWindowW(
		this->GetName(), this->GetName(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0,
		CW_USEDEFAULT, 0,
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

	ShowWindow(this->GetHandle(), nCmdShow);
	UpdateWindow(this->GetHandle());

	return;
}





ATOM DM::Window::registerWindow(WNDPROC proc) const
{
    WNDCLASSEXW wcex;

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
    wcex.lpszClassName = this->GetName();
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}





LRESULT CALLBACK DM::WndProc_Engine(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(Window::GetInstance(), MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, DM::About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;

}





INT_PTR CALLBACK DM::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
