#pragma once
#include "framework.h"

namespace DM
{
	LRESULT CALLBACK WndProc_Engine(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
}