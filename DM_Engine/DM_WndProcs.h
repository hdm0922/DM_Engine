#pragma once
#include "framework.h"

namespace DM
{
	LRESULT CALLBACK WndProc_Engine(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WndProc_TileWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	void Paint(HWND hWnd, std::function<void(HDC)> paintFunction);

	void Paint_Nothing(HDC hdc);
	void Paint_TileSheet(HDC hdc);
}