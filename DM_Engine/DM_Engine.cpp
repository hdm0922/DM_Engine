#pragma once
#include "DM_Engine.h"
#include "DM_Window.h"
#include "DM_WndProcs.h"

namespace DM
{
    Window* mainWindow;
}


int APIENTRY wWinMain(
    _In_        HINSTANCE hInstance,
    _In_opt_    HINSTANCE hPrevInstance,
    _In_        LPWSTR    lpCmdLine,
    _In_        INT       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    DM::Window::SetInstance(hInstance);

    DM::mainWindow = new DM::Window(L"Main Window", DM::WndProc_Engine, true);
    DM::mainWindow->AddSubWindow(L"Sub Window", DM::WndProc_Engine, true);

    DM::mainWindow->Show(nCmdShow);


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DMENGINE));

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    delete DM::mainWindow;

    return (int) msg.wParam;
}