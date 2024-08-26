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
#pragma comment(lib, "Msimg32.lib")



// 사용자 정의
#include "DM_Engine_Macro.h"
#include "DM_Math.h"
#include "DM_Enums.h"