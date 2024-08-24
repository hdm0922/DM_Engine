﻿#pragma once
#include "DM_Engine.h"

#include "DM_Window.h"
#include "DM_WndProcs.h"
#include "DM_Application.h"
#include "DM_ResourceManager.h"
#include "DM_Texture.h"



namespace DM
{
    Window* mainWindow;

    void GameLoop(MSG message);
    void TranslateMessage(HACCEL hAccelTable, MSG message);
    void CheckMemoryLeak();
    void LoadResources();
}





INT APIENTRY wWinMain(
    _In_        HINSTANCE hInstance,
    _In_opt_    HINSTANCE hPrevInstance,
    _In_        LPWSTR    lpCmdLine,
    _In_        INT       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    DM::CheckMemoryLeak();





    ULONG_PTR gpToken;
    Gdiplus::GdiplusStartupInput gpsi;
    Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);






    DM::Window::SetInstance(hInstance);

    DM::mainWindow = new DM::Window(L"Main Window", DM::WndProc_Engine, true);
    DM::mainWindow->CreateSubWindow(L"Sub Window", DM::WndProc_Engine, false);

    DM::mainWindow->Show(nCmdShow);

    DM::LoadResources();

    DM::Application::Initialize(DM::mainWindow);





    MSG message = {};
    DM::GameLoop(message);





    Gdiplus::GdiplusShutdown(gpToken);
    delete DM::mainWindow;
    DM::mainWindow = nullptr;





    return static_cast<INT>(message.wParam);
}





void DM::GameLoop(MSG message)
{

    HACCEL hAccelTable = LoadAccelerators(
        Window::GetInstance(),
        MAKEINTRESOURCE(IDC_DMENGINE)
    );

    while (true)
    {
        if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT) break;
            DM::TranslateMessage(hAccelTable, message);
        }
        else { DM::Application::Run(); }
    }

    return;
}





void DM::TranslateMessage(HACCEL hAccelTable, MSG message)
{

    if (TranslateAccelerator(message.hwnd, hAccelTable, &message)) return;

    TranslateMessage(&message);
    DispatchMessage(&message);

    return;
}





void DM::CheckMemoryLeak()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(232);
    return;
}





void DM::LoadResources()
{

    // TEST
    ResourceManager::LoadResource<Texture>(
        DM_TEST_TEXTURE_BMP_NAME,
        DM_TEST_TEXTURE_BMP_PATH
    );

    ResourceManager::LoadResource<Texture>(
        DM_TEST_TEXTURE_PNG_NAME,
        DM_TEST_TEXTURE_PNG_PATH
    );

}