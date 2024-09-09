#include "DM_Time.h"





namespace DM
{
	LARGE_INTEGER Time::CPU_frequency		= {};
	LARGE_INTEGER Time::CPU_frequency_prev	= {};
	LARGE_INTEGER Time::CPU_frequency_curr	= {};

	FLOAT Time::DeltaTime = 0.0f;
}





void DM::Time::Initialize()
{

	// CPU의 고유 진동수 기록
	QueryPerformanceFrequency(&Time::CPU_frequency);

	QueryPerformanceCounter(&Time::CPU_frequency_prev);

}





void DM::Time::Update()
{

	QueryPerformanceCounter(&Time::CPU_frequency_curr);

	FLOAT diff_frequency = static_cast<FLOAT>(
		Time::CPU_frequency_curr.QuadPart -
		Time::CPU_frequency_prev.QuadPart);

	Time::DeltaTime = diff_frequency / static_cast<FLOAT>(Time::CPU_frequency.QuadPart);

	Time::CPU_frequency_prev = Time::CPU_frequency_curr;

}





void DM::Time::Render(HDC hdc)
{
	//Time::renderPlayTime(hdc);
	Time::renderFPS(hdc);
}





void DM::Time::renderPlayTime(HDC hdc)
{

	static FLOAT playTime = 0.0f;

	playTime += Time::DeltaTime;

	wchar_t wstring_playTime[50] = L"";
	swprintf_s(wstring_playTime, 50, L"Time : %f", playTime);

	TextOut(hdc, 0, 0, wstring_playTime,
		static_cast<INT>(wcsnlen_s(wstring_playTime, 50)));
}





void DM::Time::renderFPS(HDC hdc)
{

	INT fps = static_cast<INT>(1.0f / Time::GetDeltaTime());

	wchar_t wstring_FPS[50] = L"";
	swprintf_s(wstring_FPS, 50, L"FPS : %d", fps);

	TextOut(hdc, 0, 20, wstring_FPS,
		static_cast<INT>(wcsnlen_s(wstring_FPS, 50)));

}
