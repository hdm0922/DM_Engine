#include "DM_PerformanceChecker.h"
#include "DM_Time.h"





namespace DM
{
	LARGE_INTEGER PerformanceChecker::frequency_start = {};
	LARGE_INTEGER PerformanceChecker::frequency_end = {};

	std::map<PerformanceChecker::Function, FLOAT> PerformanceChecker::occupancyRatio = {};
}





void DM::PerformanceChecker::Record(const Function& functionInfo)
{

	FLOAT frequencyDifference = static_cast<FLOAT>(
		PerformanceChecker::frequency_end.QuadPart -
		PerformanceChecker::frequency_start.QuadPart
	);

	FLOAT timePassed = frequencyDifference / static_cast<FLOAT>(Time::GetCPUClockCounter().QuadPart);

	auto iter = PerformanceChecker::occupancyRatio.find(functionInfo);
	if (iter == PerformanceChecker::occupancyRatio.end())
		iter = PerformanceChecker::occupancyRatio.insert({ functionInfo, 0.0f }).first;

	iter->second = (timePassed * 100.0f) / Time::GetDeltaTime();

	return;
}





FLOAT DM::PerformanceChecker::GetTotalTimeRatio()
{

	FLOAT totalTimeRatio = 0.0f;

	for (auto& iter : PerformanceChecker::occupancyRatio)
		totalTimeRatio += iter.second;

	return totalTimeRatio;
}
