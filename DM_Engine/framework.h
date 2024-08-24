#pragma once

// Windows
#define WIN32_LEAN_AND_MEAN
#define _CRTDBG_MAP_ALLOC
#include "targetver.h"
#include <windows.h>



// C, C++ Headers
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <tchar.h>
#include <crtdbg.h>
#include <cassert>
#include <functional>
#include <random>
#include <type_traits>



// data structures
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>



// gdiplus
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")



// 사용자 정의
#include "DM_Math.h"
#include "DM_Enums.h"

#define DM_RELATIVE_PATH_FROM_ENGINE_TO_RESOURCES L"..//Resources//"

#define DM_TEST_TEXTURE_BMP_NAME L"Test.bmp"
#define DM_TEST_TEXTURE_BMP_PATH L"..//Resources//AlphaCat.bmp"

#define DM_TEST_TEXTURE_PNG_NAME L"Test.png"
#define DM_TEST_TEXTURE_PNG_PATH L"..//Resources//Haley.png"
