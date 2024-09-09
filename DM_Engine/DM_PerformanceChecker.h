#pragma once
#include "framework.h"





namespace DM
{
	class PerformanceChecker;
}





class DM::PerformanceChecker
{

public:

	struct compareFunction
	{
		bool operator()(const std::function<void(HDC)>& left, const std::function<void(HDC)>& right) const
		{
			return (INT64)(&left) < (INT64)(&right);
		}
	};

public:

	static void Start() { QueryPerformanceCounter(&PerformanceChecker::frequency_start); }
	static void End()	{ QueryPerformanceCounter(&PerformanceChecker::frequency_end); }

	static void Record(std::function<void(HDC)> function, HDC hdc);

	static const std::map<std::function<void(HDC)>, FLOAT, PerformanceChecker::compareFunction>& GetOccupancyRatio() { return PerformanceChecker::occupancyRatio; }


private:

	static LARGE_INTEGER frequency_start;
	static LARGE_INTEGER frequency_end;

	static std::map<std::function<void(HDC)>, FLOAT, compareFunction> occupancyRatio;
};