#include "DM_PerformanceChecker.h"
#include "DM_Time.h"





namespace DM
{
	LARGE_INTEGER PerformanceChecker::frequency_start = {};
	LARGE_INTEGER PerformanceChecker::frequency_end = {};

	std::map<std::function<void(HDC)>, FLOAT, PerformanceChecker::compareFunction> PerformanceChecker::occupancyRatio = {};
}





void DM::PerformanceChecker::Record(std::function<void(HDC)> function, HDC hdc)
{

	FLOAT frequencyDifference = static_cast<FLOAT>(
		PerformanceChecker::frequency_end.QuadPart -
		PerformanceChecker::frequency_start.QuadPart
	);

	FLOAT timePassed = frequencyDifference / static_cast<FLOAT>(Time::GetCPUClockCounter().QuadPart);

	auto iter = PerformanceChecker::occupancyRatio.find(function);
	if (iter == PerformanceChecker::occupancyRatio.end())
		iter = PerformanceChecker::occupancyRatio.insert({ function, 0.0f }).first;

	iter->second = (timePassed * 100.0f) / Time::GetDeltaTime();

	return;
}
