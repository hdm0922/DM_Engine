#pragma once
#include "framework.h"





namespace DM
{
	class Time;
}





class DM::Time
{

public:

	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	static FLOAT GetDeltaTime() { return Time::DeltaTime; }

	static LARGE_INTEGER GetCPUClockCounter() { return Time::CPU_frequency_prev; }


	static UINT functionIdx;
	static std::vector<LARGE_INTEGER> freq_functionStart;
	static std::vector<LARGE_INTEGER> freq_functionEnd;


private:

	static void renderPlayTime(HDC hdc);
	static void renderFPS(HDC hdc);

	static void checkFunctionsPerformance();

private:

	static LARGE_INTEGER CPU_frequency;
	static LARGE_INTEGER CPU_frequency_prev;
	static LARGE_INTEGER CPU_frequency_curr;

	static FLOAT DeltaTime;


};

