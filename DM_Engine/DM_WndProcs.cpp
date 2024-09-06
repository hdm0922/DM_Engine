#include "DM_WndProcs.h"

#include "DM_Window.h"
#include "DM_ResourceManager.h"

#include "SDV_Framework.h"





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
    } break;
    case WM_PAINT: Paint(hWnd, DM::Paint_Nothing); break;
    case WM_DESTROY: PostQuitMessage(0); break;
    default: return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;

}





LRESULT CALLBACK DM::WndProc_TileWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_COMMAND: break;
    case WM_PAINT: DM::Paint(hWnd, DM::Paint_TileSheet); break;
    default: return DefWindowProc(hWnd, message, wParam, lParam);
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





void DM::Paint(HWND hWnd, std::function<void(HDC)> paintFunction)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    paintFunction(hdc);
    EndPaint(hWnd, &ps);
}





void DM::Paint_Nothing(HDC hdc)
{
}





void DM::Paint_TileSheet(HDC hdc)
{

    for (UINT iter = 0; iter < 100; iter++)
    {

        INT position_x = SDV_TILE_SIZE.x * iter;
        MoveToEx(hdc, position_x, 0, nullptr);
        LineTo(hdc, position_x, 2000);

        INT position_y = SDV_TILE_SIZE.y * iter;
        MoveToEx(hdc, 0, position_y, nullptr);
        LineTo(hdc, 2000, position_y);

    }

    Texture* tileSheet = ResourceManager::GetResource<Texture>(SDV_NAME_TEXTURE_SPRING_OUTDOOR);

    switch (tileSheet->GetTextureType())
    {
    case Enums::TextureType::bmp:
    {
        TransparentBlt(

            hdc,
            static_cast<INT>(0),
            static_cast<INT>(0),
            static_cast<INT>(tileSheet->GetWidth()),
            static_cast<INT>(tileSheet->GetHeight()),

            tileSheet->GetDeviceContext(),
            static_cast<INT>(0),
            static_cast<INT>(0),
            static_cast<INT>(tileSheet->GetWidth()),
            static_cast<INT>(tileSheet->GetHeight()),

            RGB(255, 0, 255)
        );

    } break;
    case Enums::TextureType::png:
    {
        Gdiplus::ImageAttributes image_attribute = {};

        // 투명화 시킬 색의 범위 지정
        image_attribute.SetColorKey(
            Gdiplus::Color(255, 0, 255),
            Gdiplus::Color(255, 0, 255)
        );

        Gdiplus::Graphics graphics(hdc);

        graphics.DrawImage(
            tileSheet->GetImage(),

            Gdiplus::Rect(
                static_cast<INT>(0),
                static_cast<INT>(0),
                static_cast<INT>(tileSheet->GetWidth()),
                static_cast<INT>(tileSheet->GetHeight())
            ),

            static_cast<INT>(0),
            static_cast<INT>(0),
            static_cast<INT>(tileSheet->GetWidth()),
            static_cast<INT>(tileSheet->GetHeight()),

            Gdiplus::UnitPixel,
            &image_attribute
        );

    }break;
    }

}
